    #include<bits/stdc++.h>
using namespace std;

class Employee {
    private:
        string name;
        int ID;
        double Salary;

    public:
        void get_data() {
            cout << endl << "What is the name of the employee: ";
            cin.ignore();
            getline(cin, name);

            cout << endl << "Enter employee's ID(5 digit number): ";
            cin >> ID;

            cout << endl << "What is the Salary per year of " << name << " (" << ID << ") : ";
            cin >> Salary;
        }

        void printEmployeeData() {
            cout << endl << "Employee Name: " << name;
            cout << endl << "ID: " << ID;
            cout << endl << "Salary: " << Salary;
        }

        int getID() {
            return ID;
        }

        string getName() {
            return name;
        }

        double getSalary() {
            return Salary;
        }
};

int partition(vector<Employee> &employees, int low, int high) {
    int pivot = employees[low].getID();
    int i = low + 1, j = high;

    while (i <= j) {
        while (i <= j && employees[i].getID() <= pivot) {
            i++;
        }

        while (i <= j && employees[j].getID() > pivot) {
            j--;
        }

        if (i >= j) break;

        swap(employees[i], employees[j]);
    }

    swap(employees[low], employees[j]);

    return j;
}

void quickSort(vector<Employee> &employees, int low, int high) {
    if (low < high) {
        int pi = partition(employees, low, high);
        quickSort(employees, low, pi - 1);
        quickSort(employees, pi + 1, high);
    }
}



void merge(vector<Employee> &employees, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector <Employee> left(n1), right(n2);

    for (int i =0; i < n1; i++){
        left[i] = employees[l + i];
    }
    for (int i = 0; i < n2; i++){
        right[i] = employees[mid+1+i];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2){
        if (left[i].getName() <= right[j].getName()){
            employees[k] = left[i];
            i++;
        } 

        else {
            employees[k] = right[j];
            j++;
        }

        k++;
    }

    while (i < n1){
        employees[k] = left[i];
        i++;
        k++;
    }

    while (j < n2){
        employees[k] = right[j];
        j++;
        k++;
    }
}


void mergeSort(vector<Employee> &employees, int l, int r){
    if (l < r){  // l = left most, r = right most
        int mid = l + (r - l) / 2;
        mergeSort(employees, l, mid);
        mergeSort(employees, mid + 1, r);
        merge(employees, l, mid, r);
    }
}

int main() {
    int n;
    cout << endl << "Enter the Total Number of Employee in Class: ";
    cin >> n;

    if (n <= 20) {
        cout << endl << "Please enter data for more than 20 Employees. Thank You!";
        return 0;
    }

    vector<Employee> employees(n);

    for (int i = 0; i < n; i++) {
        cout << endl << "Enter data of Employee " << i + 1 << ":";
        employees[i].get_data();
    }

    int choice = 0;
    cout << endl << "Thank You for entering Employee's data. Here are a few options to play around with: give it a try" << endl
         << "Press '1' to arrange the list of Employees according to their ID in ascending order" << endl
         << "Press '2' to arrange the list of Employees' names alphabetically in ascending order" << endl
         << "Please enter your choice now (1, 2): ";
    cin >> choice;

    if (choice != 1 && choice != 2) {
        cout << endl << "You have entered a choice out of bounds. Please re-execute the program. Thank you for using our services.";
    } 
    
    else if (choice == 1) {
        quickSort(employees, 0, employees.size() - 1);

        cout << endl << "The sorted database according to Employee ID:";
        for (int i = 0; i < n; i++) {
            cout << endl << "Employee " << i + 1 << " data:";
            employees[i].printEmployeeData();
        }
    } 
    else if (choice == 2) {
        mergeSort(employees, 0, employees.size() - 1);
        cout << endl << "The sorted database according to Employee Name:";

        for (int i = 0; i < n; i++) {
            cout << endl << "Employee " << i + 1 << " data:";
            employees[i].printEmployeeData();
        }
    }

    return 0;
}
