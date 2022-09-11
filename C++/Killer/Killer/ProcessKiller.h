#pragma once
#include <iostream>
#include <windows.h>
#include <WtsApi32.h>
#include <vector>
#include <string>
#include <sstream>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>


class ProcessKiller
{
private:
	std::vector<DWORD> ids_to_kill_processes_;
	TCHAR environment_variable_[1000];


public:
	void FindProcessesByName(TCHAR* name);
	void AddProcessId(DWORD id);
	void KillAllProcesses();
};


void ProcessKiller::FindProcessesByName(TCHAR* name)
{
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	PROCESSENTRY32 process_entry;
	process_entry.dwSize = sizeof(PROCESSENTRY32);
	//auto str = std::string(name);
	//auto wstr = std::wstring(str.begin(), str.end());
	//auto hRes = Process32First(hSnapShot, &pEntry);

	//while (hRes) {
	//	if (std::wcscmp(pEntry.szExeFile, wstr.c_str()) == 0) {
	//		killed = killProcessById(pEntry.th32ProcessID);
	//	}
	//	hRes = Process32Next(hSnapShot, &pEntry);
	//}


	//auto hRes = Process32First(hSnapShot, &proceess_entry);
	if (Process32First(hSnapShot, &process_entry)){
		while (Process32Next(hSnapShot, &process_entry)) {
			std::wstring w_name(name+'.exe');
			//TCHAR* new_name = name + '.exe';
				if (std::wcscmp(process_entry.szExeFile, w_name.c_str())==0) {
					ids_to_kill_processes_.push_back(process_entry.th32ProcessID);
				}
		}
	
	}






	//WTS_PROCESS_INFO* process_info_ptr;
	//DWORD processes_number;

	//if (WTSEnumerateProcesses(WTS_CURRENT_SERVER_HANDLE, 0, 1, &process_info_ptr, &processes_number) != 0){
	//	for (DWORD i = 0; i < processes_number; ++i){
	//		std::wstring w_str(name);
	//		if (lstrcmp(process_info_ptr[i].pProcessName, w_str.c_str()) == 0){
	//			ids_to_kill_processes_.push_back(process_info_ptr[i].ProcessId);
	//		}
	//	}
	//}
}

void ProcessKiller::AddProcessId(DWORD id) {
	ids_to_kill_processes_.push_back(id);
}

void ProcessKiller::KillAllProcesses(){

	if (GetEnvironmentVariable(TEXT("PROC_TO_KILL"), environment_variable_, sizeof(environment_variable_)) != 0){
		std::wstring w_str(environment_variable_);
		std::wstringstream w_string_stream(w_str);
		std::wstring variable;
		TCHAR delimiter = ';';
		while (std::getline(w_string_stream, variable, delimiter)){
			TCHAR temp[1000];
			lstrcpy(temp, variable.c_str());
			FindProcessesByName(temp);
			ids_to_kill_processes_.insert(ids_to_kill_processes_.end(), ids_to_kill_processes_.begin(), ids_to_kill_processes_.end());
		}
	}

	for (int i=0;i<ids_to_kill_processes_.size();++i){
		DWORD current_id= ids_to_kill_processes_[i];
		HANDLE h_process_to_kill = OpenProcess(PROCESS_ALL_ACCESS, FALSE, current_id);
		if (TerminateProcess(h_process_to_kill, 2)){
			std::cout << "Process " << current_id << " terminated" << std::endl;
		} else {
			std::cout << "Failed to terminate process " << current_id << std::endl;
		}
		CloseHandle(h_process_to_kill);
	}
}
