import java.math.BigDecimal;
import java.math.RoundingMode;

public class Employee {
  private Long ID;
  private String name;
  private BigDecimal salary;

  public Employee(Long id, String name, BigDecimal salary) {
    this.ID = id;
    this.name = name;
    this.salary = salary.setScale(2, RoundingMode.FLOOR);
  }

  public Long getID() {
    return ID;
  }

  public void setID(Long iD) {
    ID = iD;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public BigDecimal getSalary() {
    return salary;
  }

  public void setSalary(BigDecimal salary) {
    this.salary = salary;
  }

  @Override
  public String toString() {
    return String.format("id=%d, name=%s, salary=%s",
                          this.ID, this.name, this.salary.toString());
  }
}
