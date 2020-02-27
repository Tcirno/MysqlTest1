#include <iostream>
#include <mysql.h>
//#include <winsock.h>

using std::cout;
using std::endl;

int main()
{
	const char user[] = "test";
	const char pswd[] = "test123456";
	const char host[] = "localhost";
	const char table[] = "test1";
	unsigned int port = 3306;
	MYSQL myCont;
	MYSQL_RES *result = nullptr;
	MYSQL_ROW sql_row;
	int res;
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, host, user, pswd, table, port, NULL, 0))
	{
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式
		res = mysql_query(&myCont, "select * from stu");//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))//获取具体的数据
				{
					cout << "Sno:" << sql_row[0] << " ";
					cout << "Sname:" << sql_row[1] << " ";
					cout << "Ssex:" << sql_row[2] << " ";
					cout << endl;
					cout << mysql_get_client_info() << endl;
				}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
		mysql_free_result(result);
	mysql_close(&myCont);
	return 0;
}
