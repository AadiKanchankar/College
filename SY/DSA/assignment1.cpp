#include<bits/stdc++.h>
using namespace std;


class student{
	private:
		string name;
		int Roll_No;
		double SGPA;

	public:
		void get_data(){

			cout << endl << "What is the name of the student: ";
			cin >> name;

			cout << endl << "Enter student's Roll_No(last three digits of PRN): ";
			cin >> Roll_No;

			cout << endl << "What is the SGPA of " << Roll_No << " last semester: ";
			cin >> SGPA;
		}

		void printStudentData(){
			cout << endl << "Student Name: " << name;
			cout << endl << "Roll_No: " << Roll_No;
			cout << endl << "SPGA: " << SGPA;
		}

		int getRollNo() {
        	return Roll_No;
    	}

    string getName(){
    	return name;
    }

    double getSGPA(){
    	return SGPA;
    }

	
};

void insertion_sort(vector <student> &students) {
    int n = students.size();
    for (int i = 1; i < n; i++) {
        student key = students[i];
        int j = i - 1;

        while (j >= 0 && students[j].getRollNo() > key.getRollNo()) {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key;
    }
}

/*
void Shell_Sort(vector<student> &students){
	int n = students.size();
	for(int gap = n / 2; gap > 0; gap /= 2){
		for(int i = gap; i < n; i++){
			student temp = students[i];

			int j;

			for(j = i; j >= gap && students[j-gap].getName() > temp.getName(); j -= gap){
				students[j] = students[j-gap];
			}

			students[j] = temp;
		}
	}

}
*/


void Shell_Sort(vector<student> &students){
	int n = students.size();
	int gap = n / 2;
	while(gap >= 1){

		for(int j = gap; j < n; j++){
		
			for(int i = j - gap; i >= 0; i -= gap){
				student val = students[i];

				if(students[i].getName() < students[i+gap].getName())
				{
					break;
				}
				else
				{
					swap(students[i], students[i+gap]);

				}

				
			}

		}
		gap = gap / 2;
	}
}



int main() {

    int n;
    cout << endl << "Enter the Total Number of Students in Class: ";
    cin >> n;

    if(n <= 15){ 
    	cout << endl << "Please enter data for more than 15 students. Thank You!";
    	return 0;
	}

	else{

	    vector <student> students(n);

	    for (int i = 0; i < n; i++) {
	        cout << endl << "Enter data of Student " << i + 1 << ":";
	        students[i].get_data();
	    }

	    int choice = 0;
	    cout << endl << "Thank You for entering Student's data. Here are a few options to play around with: give it a try" << endl
	    			<< "Press '1' to arrange the list of students according to Roll Number in ascending order" << endl 
	    			<< "Press '2' to arrange the list of students alhpabetically in ascending order" << endl
	    			<< "Press '3' to arrange the list of students to find out the ten toppers from class in descending order" << endl
	    			<< "Please enter your choice now(1, 2, 3): ";
		cin >> choice;


	    if(choice !=  1 || choice != 2 || choice != 3){
	    	cout << endl << "You have entered a choice out of bounds. Please re-execute the program. Thank you for using our services.";
	    }

	    else if(choice == 1){
		  	insertion_sort(students);

		    cout << endl << "The sorted database according to Roll number:";
		    for (int i = 0; i < n; i++) {
		        cout << endl << "Student " << i + 1 << " data:";
		        students[i].printStudentData();
	    	}

		}
	    
	    else if(choice == 2){
		    Shell_Sort(students);
		    cout << endl << "The sorted database according to Name:";
		    
		    for(int i = 0; i < n; i++){
		    	cout << endl << "Student" << i+1 << " data:";
		    	students[i].printStudentData();
		    }
	    }

	    else if(choice == 3){
	    	cout<< endl << "Oops! Under Development... Thank You for understanding";
	    }
	}
	

    return 0;
}
