#include "stack.h"

int main()
{
	int VAL = 0;
	stack DOUNDO(100);
	DOUNDO.push(0, 0);

	int op = -1;
	while (op != 4)
	{
		system("cls");
		cout << "VAL=" << VAL << "\n" << endl;
		cout << DOUNDO << "   /   ";
		DOUNDO.show();
		cout<< "\n" << endl;
		cout << "0. +" << endl;
		cout << "1. -" << endl;
		cout << "2. UNDO" << endl;
		cout << "3. DO" << endl;
		cout << "4. exit" << endl;

		cin >> op;

		switch (op)
		{
		case 0:
		{
			int k;
			cout << "VAL += ";
			cin >> k;
			VAL += k;
			DOUNDO.push(VAL, 0);
			DOUNDO.refreshIndex();
			break;
		}

		case 1:
		{
			int k;
			cout << "VAL -= ";
			cin >> k;
			VAL -= k;
			DOUNDO.push(VAL, 0);
			DOUNDO.refreshIndex();
			break;
		}

		case 2:
		{
			if (DOUNDO.stackEMPTY(0)) break;
			DOUNDO.push(DOUNDO.pop(0), 1);
			VAL = DOUNDO.GetVAL();
			break;
		}

		case 3:
		{
			if (DOUNDO.stackEMPTY(1)) break;
			DOUNDO.push(DOUNDO.pop(1), 0);
			VAL = DOUNDO.GetVAL();
			break;
		}

		case 4:
		{
			return 0;
		}
		}
	}
	return 0;
}