/*Develop a class Employee with private data for employee name, a shift array for
a month, and total hours worked. Provide constructors for initialization and
methods for updating shifts. Include a static method to compute the total working
hours for all employees.*/
#include <iostream>
#include <string>
using namespace std;
class Employee {
    string name;
    int month[30];
    int total_hours;
    static int total_company_hours;
public:
    Employee(string m = ""):name(m),total_hours(0){
        for (int i=0;i<30;i++){
            month[i] =0;}}
    void update_shift(int day, int hours){
        if (day <1 || day >30) {
            cout <<"Invalid day! Please enter a day between 1 and 30." <<endl;}
        else{
        month[day -1] =hours;
        total_hours =total_hours+hours;
        total_company_hours =total_company_hours+hours;}}
    void display()const{
        cout <<"Employee Name: "<<name<<endl;
        cout <<"Total Hours Worked: "<<total_hours <<endl;}
    static int get_total_company_hours(){
        return total_company_hours;}};
int Employee::total_company_hours=0;
int main() {
    cout << "Enter the number of employees (max 100): ";
    int n;
    cin >> n;
    if (n < 1 || n > 100) {
        cout << "Invalid number of employees! Please enter a number between 1 and 100." << endl;}
    Employee employees[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter name for employee "<< i + 1 << ": ";
        string name;
        cin >> name;
        employees[i] = Employee(name);
        for (int j = 0; j < 30; j++) {
            cout << "Enter working hours for day " << j + 1 << ": ";
            int hours;
            cin >> hours;
            employees[i].update_shift(j + 1, hours);} }

    for (int i = 0; i < n; i++) {
        cout << "Details for Employee " << i + 1 << ":" << endl;
        employees[i].display();}
    cout << "Total working hours for all employees: " << Employee::get_total_company_hours() << endl;
    return 0;}
