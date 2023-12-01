void calculateDay1()
{
	ifstream file("input.txt");
	string str;
	string line;
	int sum = 0;
	while (getline(file, line)) {
		str = line;
		char char1=0, char2=0;
	
		for (int i = 0; i<line.size(); i++) {
			if (line[i] >= 48 && line[i] <= 57) {
				char1 = line[i];
				break;
			}
		}
		bool sameNumber = false;

		for (int i = line.size() - 1; i >= 0; i--) {
			if (line[i] >= 48 && line[i] <= 57) {
				char2 = line[i];	
				break;
			}
		}
		
		int num= 10 * (char1 - '0') + (char2 - '0');
	
		sum += num;
		cout << "SUM = " << sum << endl;


	}
	
}
