package SRP;

import java.util.Scanner;

//계산기 클래스
class Calculator {
 public int add(int a, int b) {
     return a + b;
 }

 public int subtract(int a, int b) {
     return a - b;
 }

 public int multiply(int a, int b) {
     return a * b;
 }

 public int divide(int a, int b) {
     return a / b;
 }
}

//사용자 입력 클래스
class UserInput {
 private Scanner scanner;

 public UserInput() {
     scanner = new Scanner(System.in);
 }

 public int getIntInput(String message) {
     System.out.print(message);
     return scanner.nextInt();
 }

 public char getCharInput(String message) {
     System.out.print(message);
     return scanner.next().charAt(0);
 }
}

//메인 클래스
public class Main {
	 public static void main(String[] args) {
	     UserInput userInput = new UserInput();
	     Calculator calculator = new Calculator();

	     int a = userInput.getIntInput("첫 번째 숫자를 입력하세요: ");
	     int b = userInput.getIntInput("두 번째 숫자를 입력하세요: ");
	     char operator = userInput.getCharInput("연산자를 입력하세요 (+, -, *, /): ");

	     int result;
	     switch (operator) {
	         case '+':
	             result = calculator.add(a, b);
	             System.out.println("덧셈 결과: " + result);
	             break;
	         case '-':
	             result = calculator.subtract(a, b);
	             System.out.println("뺄셈 결과: " + result);
	             break;
	         case '*':
	             result = calculator.multiply(a, b);
	             System.out.println("곱셈 결과: " + result);
	             break;
	         case '/':
	             result = calculator.divide(a, b);
	             System.out.println("나눗셈 결과: " + result);
	             break;
	         default:
	             System.out.println("올바른 연산자를 입력해주세요.");
	     }
	 }
}
