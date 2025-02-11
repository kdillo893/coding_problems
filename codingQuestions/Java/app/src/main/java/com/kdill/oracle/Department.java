package com.kdill.oracle;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Optional;
import java.util.Random;

/**
 * Department
 */
public class Department {

  private static Random rng = new Random();
  // to make this variable capacity, need to use a dynamic array or vector
  private Employee[] employees = new Employee[10];
  private int employeeCount = 0;

  // name must be unique; we will not need to enforce
  private String name;

  public Department() {
    this(genRandomDepartmentName(rng, 200));
  }

  private static String genRandomDepartmentName(Random rng, int length) {
    // compiler should condense this into a single assignment of memory
    final String upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    final String lower = upper.toLowerCase();
    final String digits = "0123456789";
    final String alphanum = upper + lower + digits;

    // avoid stringbuilder dynamic mem resizing by allocating space to start
    char[] nameChars = new char[length];
    for (int i = 0; i < length; i++) {
      int rInt = rng.nextInt(alphanum.length());
      nameChars[i] = (alphanum.charAt(rInt));
    }

    return new String(nameChars);
  }

  public Department(String name) {
    this.name = name;
  }

  public String getName() {
    return name;
  }

  public boolean addEmployee(Employee employee) {
    // if couldn't add, return false
    if (employeeCount >= 10) {
      System.err.printf("Trying to add too many employees, don't allow: Employee=%s\n", employee.toString());
      return false;
    }

    //no duplicate id's
    for (Employee existingEmp : this.employees) {
      if (existingEmp == null) continue;
      if (existingEmp.getID() == employee.getID()) {
        System.err.printf("No adding duplicate employee: %s\n", employee.toString());
        return false;
      }
    }

    this.employees[employeeCount] = employee;
    this.employeeCount++;

    return true;
  }

  public boolean removeEmployee(Employee employee) {
    // if couldn't remove, return false
    if (employeeCount <= 0 || employee == null) {
      return false;
    }

    boolean replaced = false;
    for (int i = 0; i < employeeCount; i++) {
      if (replaced) {
        employees[i - 1] = employees[i];
      } else {
        if (employee.getID() == employees[i].getID()) {
          employees[i] = null;
          replaced = true;
        }
      }
    }

    this.employeeCount--;

    return true;
  }

  public Employee[] getEmployees() {
    Employee[] employees = new Employee[this.employeeCount];
    for (int i = 0; i < employeeCount; i++) {
      employees[i] = this.employees[i];
    }

    return employees;
  }

  public int employeeCount() {
    return this.employeeCount;
  }

  public Optional<Employee> getEmployeeById(long id) {
    for (Employee employee : this.employees) {
      if (employee == null)
        continue;
      if (employee.getID() == id)
        return Optional.of(employee);
    }

    return Optional.empty();
  }

  public BigDecimal totalSalaries() {
    BigDecimal sum = new BigDecimal(0).setScale(2, RoundingMode.FLOOR);

    for (Employee emp : this.employees) {
      if (emp == null)
        continue;

      sum.add(emp.getSalary());
    }

    return sum;
  }

  public BigDecimal averageSalary() {
    return totalSalaries().divide(new BigDecimal(employeeCount));
  }

  @Override
  public String toString() {
    return super.toString() + ": name=" + this.name;
  }
}
