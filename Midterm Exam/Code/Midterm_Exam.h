



#ifndef _Midterm_Exam_H_
#define _Midterm_Exam_H_

// Struct to store data for each student
struct students
{
  char name[50];
  int ID;
  int Grade;
  char Level;
};

typedef struct node
{
	
  struct students student;
  struct node * next;
  
}node;


#define USER_NAME "admin"

#define PASSWORD  "admin" 

/*                     C Questions             */

#define C_Q1        	"1. *Question: What is the output of the following C code?*\n"\
						"c\n"\
						"#include <stdio.h>\n"\
						"int main() {\n"\
						"int x = 5;\n"\
						"printf(\"%d\", x++);\n"\
						"return 0;\n"\
						"}\n"\
						"\n"\
						"a) 5\n"\
						"b) 6\n"\
						"c) 4\n"\
						"d) 7\n"
						
#define C_A1            'b'                         // Question answer
					
#define C_Q2            "2. *Question: Which of the following is not a valid data type in C?*\n"\
						"a) float\n"\
						"b) char*\n"\
						"c) long double\n"\
						"d) boolean\n"

#define C_A2            'd'                         // Question answer

#define C_Q3            "3. *Question: What will be the value of 'result' after the following C code is executed?*\n"\
						"c\n"\
						"int a = 10, b = 3;\n"\
						"float result = (float)a / b;\n"\
						"\n"\
						"a) 3.33\n"\
						"b) 3\n\n"\
						"c) 3.0\n"\
						"d) 4\n"

#define C_A3            'a'                         // Question answer


#define C_Q4            "4. **Question: In C, what is the purpose of the typedef keyword?\n"\
						"a) To declare a new variable\n"\
						"b) To define a new data type\n"\
						"c) To include a header file\n"\
						"d) To specify the size of an array\n"

#define C_A4            'b'                         // Question answer


#define C_Q5            "5. *Question: What will be the output of the following C code?*\n"\
						"c\n"\
						"#include <stdio.h>\n"\
						"int main() {\n"\
						"int i = 0;\n"\
						"for (; i < 5; ++i)\n"\
						"printf(\"%d\", i);\n"\
						"return 0;\n"\
						"}\n"\
						"\n"\
						"a) 0 1 2 3 4\n"\
						"b) 1 2 3 4 5\n"\
						"c) 0 1 2 3\n"\
						"d) 1 2 3 4\n"

#define C_A5            'a'                         // Question answer

/*************************************************************************************************************************/
/*************************************************************************************************************************/

/*                     CPP Questions             */
#define CPP_Q1          "1. *Question: What is the output of the following C++ code?*\n"\
						"cpp\n"\
						"#include <iostream>\n"\
						"using namespace std;\n"\
						"int main() {\n"\
						"int x = 5;\n"\
						"cout << x++;\n"\
						"return 0;\n"\
						"}\n"\
						"\n"\
						"a) 5\n"\
						"b) 6\n"\
						"c) 4\n"\
						"d) 7\n"
						
#define CPP_A1          'b'                         // Question answer		

	
#define CPP_Q2          "2.*Question: Which C++ keyword is used to dynamically allocate memory?*\n"\
						"a) malloc\n"\
						"b) allocate\n"\
						"c) new\n"\
						"d) alloc\n"
						
#define CPP_A2          'c'                         // Question answer		

#define CPP_Q3          "3. **Question: What is the function of the typeid operator in C++?\n"\
						"a) Returns the size of a data type\n"\
						"b) Returns the type of an object\n"\
						"c) Checks if a variable is initialized\n"\
						"d) Converts one data type to another\n"
						
#define CPP_A3          'b'                         // Question answer		

		 
#define CPP_Q4          "4. *Question: In C++, what is a virtual function?*\n"\
						"a) A function that can be called only once\n"\
						"b) A function that can be overridden in a derived class\n"\
						"c) A function that is declared in the main function\n"\
						"d) A function that is defined outside the class\n"
						
#define CPP_A4          'b'                         // Question answer		
					
		 
#define CPP_Q5          "5. *Question: What is the output of the following C++ code?*\n"\
						"cpp\n"\
						"#include <iostream>\n"\
						"using namespace std;\n"\
						"int main() {\n"\
						"int i = 0;\n"\
						"while (i < 5) {\n"\
						"cout << i <<\" \";\n"\
						"++i;\n"\
						"return 0;\n"\
						"}\n"\
						"\n"\
						"a) 0 1 2 3 4\n"\
						"b) 1 2 3 4 5\n"\
						"c) 0 1 2 3\n"\
						"d) 1 2 3 4\n"
		
#define CPP_A5          'a'                         // Question answer				
						
/*************************************************************************************************************************/
/*************************************************************************************************************************/

/*                     PYTHON Questions             */
#define PYTHON_Q1       "1- Question: What is the output of the following Python code?\n"\
						" python\n"\
						"print(x)\nx += 1\n"\
						"print(x)\n"\
						"\n"\
						"A) 5, 5\n"\
						"B) 5, 6\n"\
						"C) 6, 6\n"\
						"D) 6, 5\n"

#define PYTHON_A1       'b'                         // Question answer	


#define PYTHON_Q2       "2. **Question: What does the pass statement do in Python?\n"\
						"a) Terminates the program\n"\
						"b) Skips the current iteration of a loop\n"\
						"c) Executes a block of code\n"\
						"d) Indicates an empty code block\n"

#define PYTHON_A2       'd'                         // Question answer	


#define PYTHON_Q3       "3. **Question: In Python, what is the purpose of the __init__ method in a class?\n"\
						"a) To initialize the class variables\n"\
						"b) To define a new instance variable\n"\
						"c) To create a new object\n"\
						"d) To print the object's state\n"
						
#define PYTHON_A3       'a'                         // Question answer	


#define PYTHON_Q4       "4. *Question: What will be the output of the following Python code?*\n"\
						"python\n"\
						"numbers = [1, 2, 3, 4, 5]\n"\
						"print(numbers[2:4])\n"\
						"\n"\
						"a) [1, 2]\n"\
						"b) [2, 3]\n"\
						"c) [3, 4]\n"\
						"d) [3, 4, 5]\n"

#define PYTHON_A4       'c'                         // Question answer	
					
						
#define PYTHON_Q5       "5. *Question: Which of the following is a correct way to open a file in Python for reading and writing?*\n"\
						"a) open(\"file.txt\", \"rw\")\n"\
						"b) open(\"file.txt\", \"r+\")\n"\
						"c) open(\"file.txt\", \"w+\")\n"\
						"d) open(\"file.txt\", \"a\")\n"

#define PYTHON_A5       'c'                         // Question answer	

/*************************************************************************************************************************/
/*************************************************************************************************************************/

/*                     JAVA Questions               */

#define JAVA_Q1         "1. *Question: What is the output of the following Java code?*\n"\
						"java\n"\
						"public class Test {\n"\
						"public static void main(String[] args) {\n"\
						"int x = 5;\n"\
						"System.out.print(x++);\n"\
						"}\n"\
						"}\n"\
						"\n"\
						"a) 5\n"\
						"b) 6\n"\
						"c) 4\n"\
						"d) 7\n"

#define JAVA_A1         'b'							// Question answer

#define JAVA_Q2 		"2. *Question: Which keyword is used to prevent inheritance in Java?*\n"\
						"a) private\n"\
						"b) static\n"\
						"c) final\n"\
						"d) abstract\n"


#define JAVA_A2         'C'                         // Question answer


#define JAVA_Q3 		"3. **Question: What is the purpose of the super keyword in Java?\n"\
						"a) Calls the parent class constructor\n"\
						"b) Calls a static method in the parent class\n"\
						"c) Refers to the current instance of the class\n"\
						"d) Indicates the end of a method\n"


#define JAVA_A3         'a'                         // Question answer


#define JAVA_Q4    		"4. *Question: In Java, what is the default value of a boolean variable?*\n"\
						"a) false\n"\
						"b) true\n"\
						"c) 0\n"\
						"d) null\n"
						
						
#define JAVA_A4         'a'                         // Question answer


#define JAVA_Q5  		"5. *Question: What will be the output of the following Java code?*\n"\
						"java\n"\
						"public class Test {\n"\
						"public static void main(String[] args) {\n"\
						"for (int i = 0; i < 5; ++i)\n"\
						"System.out.print(i + \n"\
						");\n"\
						"}\n"\
						"}\n"\
						"\n"\
						"a) 0 1 2 3 4\n"\
						"b) 1 2 3 4 5\n"\
						"c) 0 1 2 3\n"\
						"d) 1 2 3 4\n"
						
						
#define JAVA_A5         'a'                         // Question answer


// declaration of all function
void teacher_mode();
void student_mode();
void add_student ();
void print_report();

void show_exam (node * ptr);

void PYTHON_exam(node * ptr);
void JAVA_exam  (node * ptr);
void CPP_exam   (node * ptr);
void C_exam     (node * ptr);


#endif