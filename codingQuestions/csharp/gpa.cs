using System;

// I forgot which tutorial I was following to do this...
// looks like it was this:
// https://learn.microsoft.com/en-us/training/modules/guided-project-calculate-final-gpa/

namespace Gpa {

  class MainClass {
    public static void Main (string[] args) {

      string studentName = "Sophia Johnson";
      string course1Name = "English 101";
      string course2Name = "Algebra 101";
      string course3Name = "Biology 101";
      string course4Name = "Computer Science I";
      string course5Name = "Psychology 101";


      int course1Credit = 3;
      int course2Credit = 3;
      int course3Credit = 4;
      int course4Credit = 4;
      int course5Credit = 3;

      int gradeA = 4;
      int gradeB = 3;

      int course1Grade = gradeA;
      int course2Grade = gradeA;
      int course3Grade = gradeB;
      int course4Grade = gradeB;
      int course5Grade = gradeA;


      int totalCreditHours = 0;
      totalCreditHours+=course1Credit;
      totalCreditHours+=course2Credit;
      totalCreditHours+=course3Credit;
      totalCreditHours+=course4Credit;
      totalCreditHours+=course5Credit;

      int totalGradePoints = 0;
      totalGradePoints += course1Credit * course1Grade; 
      totalGradePoints += course2Credit * course2Grade; 
      totalGradePoints += course3Credit * course3Grade; 
      totalGradePoints += course4Credit * course4Grade; 
      totalGradePoints += course5Credit * course5Grade; 

      decimal gradePointAverage = (decimal) totalGradePoints / totalCreditHours;
      int gpaIntFloor = (int) gradePointAverage; 
      int gpaFirstDec = (int) (gradePointAverage * 10) % 10;
      int gpaSecondDec = (int) (gradePointAverage * 100) % 10;

      Console.WriteLine($"Student: {studentName}");
      Console.WriteLine("GradePoints\tCreditHours");
      Console.WriteLine($"{totalGradePoints}\t\t\t{totalCreditHours}");
      Console.WriteLine($"Total GPA: {gpaIntFloor}.{gpaFirstDec}{gpaSecondDec}\n");

      Console.WriteLine($"{course1Name}\t\t{course1Grade}\t{course1Credit}");
      Console.WriteLine($"{course2Name}\t\t{course2Grade}\t{course2Credit}");
      Console.WriteLine($"{course3Name}\t\t{course3Grade}\t{course3Credit}");
      Console.WriteLine($"{course4Name}\t{course4Grade}\t{course4Credit}");
      Console.WriteLine($"{course5Name}\t\t{course5Grade}\t{course5Credit}");

    }
  }
}
