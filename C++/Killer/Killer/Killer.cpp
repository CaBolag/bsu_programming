#include"ProcessKiller.h"


int main(int argc, char* argv[])
{
	ProcessKiller process_killer;
	
	if (strcmp(argv[0], "id") == 0){
		process_killer.AddProcessId(atoi(argv[2]));
	} else if (strcmp(argv[0], "name") == 0) {
		std::string str(argv[1]);
		std::wstring w_str(str.begin(), str.end());
		TCHAR temp[1000];
		lstrcpy(temp, w_str.c_str());
		process_killer.FindProcessesByName(temp);
	}

	process_killer.KillAllProcesses();

	return 0;
}
