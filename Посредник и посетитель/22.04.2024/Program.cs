using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LessonTasks
{
    internal static class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter task number:");
            int taskNumber = int.Parse(Console.ReadLine());
            switch (taskNumber)
            {
                case 1: SolveTask1(); break;
                case 2: SolveTask2(); break;
                case 3: SolveTask3(); break;
                case 4: SolveTask4(); break;
                case 5: SolveTask5(); break;
                case 6: SolveTask6(); break;
                case 7: SolveTask7(); break;
                default: Console.WriteLine("Unknown task"); break;
            }
        }

        private static void SolveTask1()
        {
            Console.WriteLine("Задание 1");
            Console.Write("Enter a number from 1 to 100: ");
            int number = Convert.ToInt32(Console.ReadLine());
            if (number <0|| number>100)
                Console.WriteLine("Mistake");
            if (number %3==0)
                Console.WriteLine("Fizz");
            if (number %5==0)
                Console.WriteLine("Buzz");
            if (number %3==0&&number %5==0)
                Console.WriteLine("Fizz Buzz");

            else
                Console.WriteLine(number);
        }

        private static void SolveTask2()
        {


            Console.WriteLine("Задание 2");
            Console.WriteLine("Enter a number and a percentage of it");
            Console.Write("Enter a number:  ");
            double number = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter percentage of it:  ");
            double percentage = Convert.ToDouble(Console.ReadLine());
            double result = (number/100)*percentage;
            Console.WriteLine(result);
        }

        private static void SolveTask3()
        {
            Console.WriteLine("Задание 3");
            Console.WriteLine("Enter 4 digits");
            Console.Write("Enter a number_1:  ");
            int number_1 = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter a number_2:  ");
            int number_2 = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter a number_3:  ");
            int number_3 = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter a number_4:  ");
            int number_4 = Convert.ToInt32(Console.ReadLine());
            int result = 1000*number_1+100*number_2+10*number_3+number_4;
            Console.WriteLine(result);
        }

        private static void SolveTask4()
        {
            Console.WriteLine("Задание 4");
            Console.WriteLine("Enter a 6 digit number");
            double number = Convert.ToDouble(Console.ReadLine());
            if (number>99999 && number<1000000)
            {
                Console.Write("Enter a number_1:  ");
                int number_3 = Convert.ToInt32(Console.ReadLine());
                if (number_3>0&&number_3<7)
                {
                    Console.Write("Enter a number_2:  ");
                    int number_5 = Convert.ToInt32(Console.ReadLine());
                    if (number_5>0&&number_5<7)
                    {
                        double x = 10;
                        double number_11;
                        double number_13;
                        double number_14;
                        number_13=(number%Math.Pow(x, 6-number_3+1))-(number%Math.Pow(x, 6-number_3));
                        number_14=(number%Math.Pow(x, 6-number_5+1))-(number%Math.Pow(x, 6-number_5));
                        number_11=number-number_13-number_14;
                        number_13=number_13*(Math.Pow(x, number_3-number_5));
                        number_14=number_14*(Math.Pow(x, number_5-number_3));
                        number_11=number_11+number_13+number_14;
                        Console.WriteLine(number_11);
                    }
                    else
                    {
                        Console.WriteLine("Mistake");
                    }

                }
                else
                {
                    Console.WriteLine("Mistake");
                }

            }
            else
            {
                Console.WriteLine("Mistake");
            }
        }

        private static void SolveTask5()
        {
            
            Console.WriteLine("Задание 5");
            Console.WriteLine("Enter the date: day month year.");
          int data = Convert.ToInt32(Console.ReadLine());
            if (data>9999999 && data<100000000)
            {
                double number_13;
                number_13=data%10000;
                //number_13=number_13%1000;
                if (number_13>9999&&number_13<30000)
                {
                    Console.WriteLine("Winter Wednesday.");
                }
                Console.WriteLine(number_13);
            }
            //Не понял задание
            
            
        }
        private static void SolveTask6()
        {
            Console.WriteLine("Задание 6");
            Console.WriteLine("Enter the temperature.");
            Console.WriteLine("In Fahrenheit, press f.");
            Console.WriteLine("In Celsius, press c.");



            // (F — 32): 1,8 = С.
            char taskTemperature = char.Parse(Console.ReadLine());
            switch (taskTemperature)
            {
                case 'f': Temperature_F(); break;
                case 'c': Temperature_C(); break;
               
                default: Console.WriteLine("Unknown task"); break;
            }
             static void Temperature_F()
            {
                Console.WriteLine("Enter the temperature in Celsius.");
                double temperature = Convert.ToDouble(Console.ReadLine());
                temperature=(temperature*1.8)+32;
                Console.WriteLine("Temperature in Fahrenheit :", temperature);
                Console.WriteLine( temperature);
            }
            static void Temperature_C()
            {
                Console.WriteLine("Enter the temperature in Fahrenheit.");
                double temperature = Convert.ToDouble(Console.ReadLine());
                temperature=(temperature=32)/1.8;
                Console.WriteLine("Temperature in Celsius :" ,temperature) ; 
                Console.WriteLine( temperature);
            }
        }
        private static void SolveTask7()
        {
            Console.WriteLine("Задание 7");
            Console.WriteLine("Enter 2 digits");
            Console.Write("Enter a number_1:  ");
            int number_1 = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter a number_2:  ");
            int number_2 = Convert.ToInt32(Console.ReadLine());
            if (number_1<number_2)
            {
                int number_3 = number_2-number_1+1;
                if (number_3%2==0) {

                    number_3 = number_3/2;
                    Console.WriteLine("Even numbers:");
                    Console.WriteLine(number_3);
                    Console.WriteLine("Odd numbers:");
                    Console.WriteLine(number_3);

                }
                else 
                {
                    if (number_1%2==0)
                    {
                        number_3=(number_2-number_1+2)/2;
                        Console.WriteLine("Even numbers:");
                        Console.WriteLine(number_3);
                        Console.WriteLine("Odd numbers:");
                        Console.WriteLine(number_3-1);
                    }
                    else
                    {
                        number_3=(number_2-number_1+2)/2;
                        Console.WriteLine("Even numbers:");
                        Console.WriteLine(number_3-1);
                        Console.WriteLine("Odd numbers:");
                        Console.WriteLine(number_3);
                    }
                }
                

            }
            else
            {
                int number_3 = number_1-number_2+1;
                if (number_3%2==0)
                {

                    number_3 = number_3/2;
                    Console.WriteLine("Even numbers:");
                    Console.WriteLine(number_3);
                    Console.WriteLine("Odd numbers:");
                    Console.WriteLine(number_3);

                }
                else
                {
                    if (number_1%2==0)
                    {
                        number_3=(number_1-number_2+2)/2;
                        Console.WriteLine("Even numbers:");
                        Console.WriteLine(number_3);
                        Console.WriteLine("Odd numbers:");
                        Console.WriteLine(number_3-1);
                    }
                    else
                    {
                        number_3=(number_1-number_2+2)/2;
                        Console.WriteLine("Even numbers:");
                        Console.WriteLine(number_3-1);
                        Console.WriteLine("Odd numbers:");
                        Console.WriteLine(number_3);
                    }
                }
            }
        }
        private static int ParseSingleNumberArgument(string[] args)
        {
            if (args.Length != 1)
                throw new ApplicationException("args.Length != 1");

            return int.Parse(args[0]);
        }
    }
}
