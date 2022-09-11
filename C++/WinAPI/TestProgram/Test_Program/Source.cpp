#include<windows.h>
#include<string>
#include<cstdio>
#include"TestProgram.h"

#include"resource.h"

INT_PTR CALLBACK    DlgProc(HWND, UINT, WPARAM, LPARAM);


void ShowOptions(HWND hDlg,Question question) {
    if (question.GetType() == "radio") {
        for (int i = 0; i < question.GetAnswersOptions().size(); ++i) {
            ShowWindow(GetDlgItem(hDlg, IDC_RADIO1 + i), SW_SHOWNORMAL);
            SetDlgItemText(hDlg, IDC_RADIO1 + i, question.GetAnswersOptions()[i].c_str());
        }
        for (int i = question.GetAnswersOptions().size(); i < 3; i++) {
            ShowWindow(GetDlgItem(hDlg, IDC_RADIO1 + i), SW_HIDE);
        }
    }

    if (question.GetType() == "check") {
        for (int i = 0; i < 5; ++i) {
            ShowWindow(GetDlgItem(hDlg, IDC_CHECK1 + i), SW_SHOWNORMAL);
            SetDlgItemText(hDlg, IDC_CHECK1 + i, question.GetAnswersOptions()[i].c_str());
        }
        for (int i = question.GetAnswersOptions().size(); i < 5; i++) {
            ShowWindow(GetDlgItem(hDlg, IDC_CHECK1 + i), SW_HIDE);
        }
    }
}


std::vector<int> ReadAnswers(HWND hDlg, Question question) {
    std::vector<int> answers;
    int answer_id=0;// answer_id = i
    if (question.GetType() == "radio") {
        for (int i = 0; i < question.GetAnswersOptions().size(); ++i) {
            if (IsDlgButtonChecked(hDlg, IDC_RADIO1 + i)== BST_CHECKED) {
                answer_id++;
                answers.push_back(answer_id);
            }
        }
    }

    if (question.GetType() == "check") {
        for (int i = 0; i < question.GetAnswersOptions().size(); ++i) {
            if (IsDlgButtonChecked(hDlg, IDC_CHECK1 + i) == BST_CHECKED) {
                answer_id++;
                answers.push_back(answer_id);
            }
        }
    }
    return answers;
}




int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
	return 0;
}



INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    TestProgram program;
    CHAR file_name[150] = { '\0' };
    static int current_question_id = 0;
    std::vector<Question> questions;
   

    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        for (int i = 0; i < 3; ++i) {
            ShowWindow(GetDlgItem(hDlg, IDC_RADIO1 + i), SW_HIDE);
        }
        for (int i = 0; i < 5; ++i) {
            ShowWindow(GetDlgItem(hDlg, IDC_CHECK1 + i), SW_HIDE);
        }

        ShowWindow(GetDlgItem(hDlg, IDC_BUTTON_PREV), SW_HIDE);
        ShowWindow(GetDlgItem(hDlg, IDC_BUTTON_NEXT), SW_HIDE);

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }

        switch (LOWORD(wParam))
        {
        case IDC_BUTTON_OPEN://file open
            OPENFILENAME ofn;
            ZeroMemory(&ofn, sizeof(ofn));
            ofn.lStructSize = sizeof(ofn);
            ofn.hwndOwner = NULL;
            ofn.lpstrFile = file_name;
            ofn.nMaxFile = sizeof(file_name);
            ofn.lpstrFilter = "All Files\0*.*\0\0";
            ofn.nFilterIndex = 1;
            ofn.lpstrFileTitle = NULL;
            ofn.nMaxFileTitle = 0;
            ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

            if (GetOpenFileName(&ofn)) {

                program.UploadQuestions(std::string(file_name));
                

                //ShowWindow(GetDlgItem(hDlg, IDC_BUTTON_PREV),SW_SHOWNORMAL);
                ShowWindow(GetDlgItem(hDlg, IDC_BUTTON_NEXT), SW_SHOWNORMAL);
                questions = program.GetQuestions();
                
                current_question_id++;
                Question question = questions[current_question_id-1];

                SetDlgItemText(hDlg, IDC_EDIT1, question.GetQuestionText().c_str());
                ShowOptions(hDlg, question);
            }
            break;

         

            case IDC_BUTTON_NEXT:
            {
                ShowWindow(GetDlgItem(hDlg, IDC_BUTTON_PREV), SW_SHOWNORMAL);
                Question question = questions[current_question_id - 1];
                std::vector<int> current_answers = ReadAnswers(hDlg, question);
                program.ChangeAnswer(current_question_id, current_answers);
                current_question_id++;
                question = questions[current_question_id - 1];
                SetDlgItemText(hDlg, IDC_EDIT1, question.GetQuestionText().c_str());
                ShowOptions(hDlg, question);
                break;
            }

            case IDC_BUTTON_PREV:
            {
                
                Question question = questions[current_question_id - 1];
                std::vector<int> current_answers = ReadAnswers(hDlg, question);
                program.ChangeAnswer(current_question_id, current_answers);
                current_question_id--;
                question = questions[current_question_id - 1];
                SetDlgItemText(hDlg, IDC_EDIT1, question.GetQuestionText().c_str());
                ShowOptions(hDlg, question);
                break;
            }
           
            case IDC_BUTTON_FINISH:
            {
                std::vector<bool> result = program.GetResult();
                std::ofstream out("Result.txt");
                out << "Wrong answers: ";
                for (int i = 0; i < result.size(); i++) {
                    if (result[i] == false) {
                        out << i+1;
                    }
                }
                EndDialog(hDlg, LOWORD(wParam));
            }


        default:
            break;
        }
        return (INT_PTR)TRUE;
    default:
        return (INT_PTR)FALSE;
        break;
    }
    return (INT_PTR)TRUE;
}