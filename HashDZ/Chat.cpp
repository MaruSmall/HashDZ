#include "Chat.h"

Chat::Chat()
{
	data_count = 0;
	data = new AuthData[mem_size];
}

Chat::~Chat()
{
	delete[] data;
}

void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length)
{
	uint* hash = sha1(_pass, pass_length);
	add(_login, hash);

}

bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length)
{
	uint index, i = 0;

	for (; i < mem_size; i++)
	{
		index = hfunc(_login, i * i);

		if (data[index].status == free) {
			return false;
		}

		if (data[index].status == engaged && !strcmp(_login, data[index].login))
		{
			break;
		}
	}
	if (i >= data_count)
	{
		return false;
	}

	uint* PAShash = sha1(_pass, pass_length);

	if (!memcmp(data[index].pass_sha1_hash, PAShash, SHA1HASHLENGTHBYTES))
	{
		delete[] PAShash;
		return true;
	}

	return false;
}

int Chat::hfunc(char* _login, int dif) {
	uint counter = 0;
	uint sum = 0;
	while (counter < strlen(_login))
	{
		sum += (uint)_login[counter];
		counter++;
	}
	const double A = 0.7;
	return int((SIZE * (A * sum - int(A * sum)) + dif)) % SIZE;
}


void Chat::resize()
{
	AuthData* temp = data;
	mem_size *= 2;
	data = new AuthData[mem_size];
	data_count = 0;
	
	for (int i = 0; i < mem_size / 2; i++)
	{
		if (temp[i].status == engaged)
		{
			uint* PASSHash = new uint[SHA1HASHLENGTHUINTS];
			memcpy(PASSHash, temp[i].pass_sha1_hash, SHA1HASHLENGTHBYTES);
			add(temp[i].login, PASSHash);
		}
	}

	delete[] temp;
}

void Chat::add(char _login[LOGINLENGTH], uint* hash)
{
	uint index = -1, i = 0;
	for (; i < mem_size; i++)
	{
		index = hfunc(_login, i * i);
		if (data[index].status == Status::free)
		{
			break;
		}
	}

	if (i >= mem_size)
	{
		resize();
		for (; i < mem_size; i++)
		{
			index = hfunc(_login, i * i);
			if (data[index].status == free)
			{
				break;
			}
		}
	}

	data[index] = AuthData(_login, hash);
	data[index].status = engaged;
	data_count++;
}
void Chat::deluser(char _login[LOGINLENGTH])
{
	int index = -1, i = 0;
	for (; i < mem_size; i++)
	{
		index = hfunc(_login, i * i);
		if (data[index].status == engaged && !strcmp(data[index].login, _login)) 
		{
			data[index].status = deleted;
			data_count--;
			
			return;
		}

		else if (data[index].status == free)
		{
			return;
		}
	}
}
