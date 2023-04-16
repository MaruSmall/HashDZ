#include <iostream>
#include "Chat.h"

int main()
{
	Chat chat;

	chat.reg((char*)"Vasia", (char*)"hrthdgfh", strlen("hrthdgfh"));
	chat.reg((char*)"Masha", (char*)"fddgfnh", strlen("fddgfnh"));
	chat.reg((char*)"Misha", (char*)"hghghjj", strlen("hghghjj"));
	chat.reg((char*)"Petia", (char*)"fgjffjfgj", strlen("fgjffjfgj"));
	chat.reg((char*)"Valia", (char*)"fgnfgn", strlen("fgnfgn"));
	chat.reg((char*)"Serge", (char*)"tyru", strlen("tyru"));

	chat.login((char*)"Vasia", (char*)"hrthdgfh", strlen("hrthdgfh"));
	chat.login((char*)"Masha", (char*)"fddgfnh", strlen("fddgfnh"));
	chat.login((char*)"Misha", (char*)"hghghjj", strlen("hghghjj"));
	chat.login((char*)"Petia", (char*)"fgjffjfgj", strlen("fgjffjfgj"));
	chat.login((char*)"Valia", (char*)"fgnfgn", strlen("fgnfgn"));
	chat.login((char*)"Serge", (char*)"tyru", strlen("tyru"));

	chat.deluser((char*)"Vasia");
	chat.deluser((char*)"Masha");
	chat.deluser((char*)"Misha");
	chat.deluser((char*)"Petia");
	chat.deluser((char*)"Valia");
	chat.deluser((char*)"Serge");
}

