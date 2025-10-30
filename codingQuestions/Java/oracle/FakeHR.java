import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.Random;

/**
 * FakeHR
 */
public class FakeHR {
  public static void main(String[] args) {
    Random rnd = new Random();

    long idRolling = 1;
    List<Employee> employees = new ArrayList<>();
    for (;idRolling < 100; idRolling++) {

      Employee emp = new Employee(idRolling, "Jeff" + idRolling,
          new BigDecimal(rnd.nextLong(15000,1000000)).setScale(2, RoundingMode.FLOOR));
      employees.add(emp);
    }

    //System.out.println(employees);

    Department clothesDep = new Department("Clothing Department");
    Department shoeDep = new Department("Shoe Department");
    Department foodDep = new Department("Food Department");

    System.out.println(clothesDep);

    //adding 11 employees to the clothes department, seeing if it doesn't break
    for (int i = 0; i < 11; i++)  {
      clothesDep.addEmployee(employees.get(rnd.nextInt(employees.size())));
    }

    //print all the employees by line:
    for (Employee employee : clothesDep.getEmployees()) {
      System.out.println(employee);
    }

    Employee jeff3 = clothesDep.getEmployees()[3];
    System.out.println(jeff3);
    System.out.println("Getting employee: " + jeff3);

    clothesDep.removeEmployee(jeff3);

    System.out.println("Removed Jeff3");

    //can i get jeff 3?
    Optional<Employee> optJeff = clothesDep.getEmployeeById(jeff3.getID());
    System.out.println("Jeff3?: " + optJeff);
    
  }
}
