#include"OrderFile.h"
#include<fstream>
OrderFile::OrderFile()
{
	ifstream ifs(ORDER_FILE, ios::in);

	string date, noon, room, status;
	string StudentID;

	Size = 0;

	while (ifs >> date && ifs >> noon && ifs >> room && ifs >> StudentID && ifs >> status)
	{
		

		string key, value;

		map<string, string> m;

		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = noon.find(":");
		if (pos != -1)
		{
			key = noon.substr(0, pos);
			value = noon.substr(pos + 1, noon.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = room.find(":");
		if (pos != -1)
		{
			key = room.substr(0, pos);
			value = room.substr(pos + 1, room.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = StudentID.find(":");
		if (pos != -1)
		{
			key = StudentID.substr(0, pos);
			value = StudentID.substr(pos + 1, StudentID.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		OrderData.insert(make_pair(Size, m));
		Size++;

	}
	ifs.close();
}

void OrderFile::updateOrder()
{
	if (this->Size == 0)
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);

	for (int i = 0; i < Size; i++)
	{
		ofs << "date:" << this->OrderData[i]["date"] << " ";
		ofs << "noon:" << OrderData[i]["noon"] << " ";
		ofs << "room:" << OrderData[i]["room"] << " ";
		ofs << "StudentID:" << OrderData[i]["StudentID"] << " ";
		ofs << "status:" << OrderData[i]["status"] << endl;
	}

	ofs.close();
}
