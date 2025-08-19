// initialize variables - graded assignments 
int currentAssignments = 5;

int[] sophia = {93, 87, 98, 95, 100};
int sophia1 = 93;
int sophia2 = 87;
int sophia3 = 98;
int sophia4 = 95;
int sophia5 = 100;

int nicolas1 = 80;
int nicolas2 = 83;
int nicolas3 = 82;
int nicolas4 = 88;
int nicolas5 = 85;

int zahirah1 = 84;
int zahirah2 = 96;
int zahirah3 = 73;
int zahirah4 = 85;
int zahirah5 = 79;

int jeong1 = 90;
int jeong2 = 92;
int jeong3 = 98;
int jeong4 = 100;
int jeong5 = 97;

int sophiaSum = 0, zahirahSum = 0, nicolasSum = 0, jeongSum = 0;

sophiaSum += sophia1 + sophia2 + sophia3 + sophia4 + sophia5;
nicolasSum += nicolas1 + nicolas2 + nicolas3 + nicolas4 + nicolas5;
zahirahSum += zahirah1 + zahirah2 + zahirah3 + zahirah4 + zahirah5;
jeongSum += jeong1 + jeong2 + jeong3 + jeong4 + jeong5;

decimal sophiaScore = (decimal) sophiaSum / currentAssignments;
decimal nicolasScore = (decimal) nicolasSum / currentAssignments;
decimal zahirahScore = (decimal) zahirahSum / currentAssignments;
decimal jeongScore = (decimal) jeongSum / currentAssignments;

var gradeScore = (decimal score) => {
    if (score > 100) {
        return "A++";
    } else if (score >= 97) {
        return "A+";
    } else if (score >= 93) {
        return "A";
    } else if (score >= 90) {
        return "A-";
    } else if (score >= 87) {
        return "B+";
    } else if (score >= 83) {
        return "B";
    } else if (score >= 80) {
        return "B-";
    } else if (score >= 77) {
        return "C+";
    } else if (score >= 73) {
        return "C";
    } else if (score >= 70) {
        return "C-";
    } else if (score >= 67) {
        return "D+";
    } else if (score >= 63) {
        return "D";
    } else if (score >= 60) {
        return "D-";
    } else {
        return "F";
    }
};


Console.WriteLine("Student\t\tGrade\n");
Console.WriteLine("Sophia:\t\t" + sophiaScore + " " + gradeScore(sophiaScore));
Console.WriteLine("Nicolas:\t" + nicolasScore + " " + gradeScore(nicolasScore));
Console.WriteLine("Zahirah:\t" + zahirahScore + " " + gradeScore(zahirahScore));
Console.WriteLine("Jeong:\t\t" + jeongScore + " " + gradeScore(jeongScore));

