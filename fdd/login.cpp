#include<fstream>
#include<string.h>

using namespace std;

class file_reader
{
public:
	char username[20], password[20];
};

int verify(char username[20], char password[20])
{
	file_reader reader;
	ifstream fin("secure.dat", ios::in|ios::binary);
    int flag = 0;
	while(fin.read((char*)&reader, sizeof(reader)))
	{
		if(strcmp(reader.username, username)==0 && strcmp(reader.password, password)==0)
		{
			flag = 1;
			break;
		}
	}	
	fin.close();
	if(flag == 0)
	{
		return 1;
	}
	else if(flag == 1)
	{
		return 2;
	}
}

void signup()
{
	file_reader writer;
	cout<<"---------------------<<SIGN-UP>>--------------------\n";
	cout<<"Username: ";
	cin>>writer.username;
	cout<<"Password: ";
	cin>>writer.password;
	
	ofstream fout("secure.dat", ios::app|ios::binary);

	fout.write((char*)&writer, sizeof(writer));

	fout.close();
}
