#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char name[50];
    int emp_id;
    float salary;
    char job_title[50];
};

struct Employee employees[MAX_EMPLOYEES];
int num_employees = 0;

void add_employee() {
    if (num_employees >= MAX_EMPLOYEES) {
        printf("Error: Maximum number of employees reached\n");
        return;
    }

    struct Employee new_employee;

    printf("Enter employee name: ");
    scanf("%s", new_employee.name);

    printf("Enter employee ID: ");
    scanf("%d", &new_employee.emp_id);

    printf("Enter employee salary: ");
    scanf("%f", &new_employee.salary);

    printf("Enter employee job title: ");
    scanf("%s", new_employee.job_title);

    employees[num_employees] = new_employee;
    num_employees++;

    printf("Employee added successfully\n");
}

void remove_employee() {
    int emp_id;

    printf("Enter employee ID: ");
    scanf("%d", &emp_id);

    for (int i = 0; i < num_employees; i++) {
        if (employees[i].emp_id == emp_id) {
            for (int j = i; j < num_employees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            num_employees--;
            printf("Employee removed successfully\n");
            return;
        }
    }

    printf("Employee not found\n");
}

void display_employee(struct Employee employee) {
    printf("%s (ID: %d)\n", employee.name, employee.emp_id);
    printf("Salary: %.2f\n", employee.salary);
    printf("Job Title: %s\n", employee.job_title);
}

void list_employees() {
    if (num_employees == 0) {
        printf("No employees found\n");
        return;
    }

    for (int i = 0; i < num_employees; i++) {
        display_employee(employees[i]);
        printf("\n");
    }
}

void update_employee_salary() {
    int emp_id;
    float new_salary;

    printf("Enter employee ID: ");
    scanf("%d", &emp_id);

    for (int i = 0; i < num_employees; i++) {
        if (employees[i].emp_id == emp_id) {
            printf("Enter new salary: ");
            scanf("%f", &new_salary);
            employees[i].salary = new_salary;
            printf("Salary updated successfully\n");
            return;
        }
    }

    printf("Employee not found\n");
}

int main() {
    int choice;

    while (1) {
        printf("Employee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Remove Employee\n");
        printf("3. List Employees\n");
        printf("4. Update Employee Salary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                remove_employee();
                break;
            case 3:
                list_employees();
                break;
            case 4:
                update_employee_salary();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        printf("\n");
    }

    return 0;
}
