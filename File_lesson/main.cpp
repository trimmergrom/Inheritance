#include <iostream>
#include <fstream>

//#define WRITE_TO_FILE

void main()
{
#ifdef WRITE_TO_FILE
	std::cout << "Htllo World!" << std::endl;

	std::ofstream fout;
	fout.open("File.txt", std::ios_base::app);
	//app (Append)
	fout << "Htllo World!" << std::endl;
	fout.close();

	system("notepad File.txt");
#endif // WRITE_TO_FILE

	std::ifstream fin("File.txt");
	if (fin.is_open())
	{
		//Read file
		const unsigned int SIZE = 256;
		char buffer[SIZE]{};
		while (!fin.eof())//while not end_of_file
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			std::cout << buffer << std::endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << std::endl;
	}

	
}
