using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Globalization;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;
using System.Collections.Generic;

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
                default: Console.WriteLine("Unknown task"); break;
            }


        }

        private static void SolveTask1()
        {
            Console.WriteLine("A calculator application" +
                " for converting numbers" +
                "\r\nfrom one calculus system to another");
            Console.WriteLine("From decimal to binary number 1");
            Console.WriteLine("From decimal to hexadecimal number 2");
            int taskNumber_1 = int.Parse(Console.ReadLine());
            switch (taskNumber_1)
            {
                case 1: SolveTask1(); break;
                case 2: SolveTask2(); break;
                    ;

                default: Console.WriteLine("Unknown task"); break;
            }


            static void SolveTask1() {
                Console.WriteLine("The direction of number translation");

                int number = Convert.ToInt32(Console.ReadLine());

                Convert.ToString(number, 2);
                Console.WriteLine(Convert.ToString(number, 2));
            }
            static void SolveTask2()
            {
                Console.WriteLine("The direction of number translation");

                int number = Convert.ToInt32(Console.ReadLine());

                Console.WriteLine(String.Format("{0:X}", number));
            }

        }

        private static void SolveTask2()
        {
           

            Console.WriteLine("Enter the number from 0 to 9 in words");
            string str = Console.ReadLine(); ;
            int number;
            if (str=="zero")
            {
                number=0;
                Console.WriteLine(number);
            }
            else if (str=="one")
            {
                number=1;
                Console.WriteLine(number);
            }
            else if (str=="two")
            {
                number=2;
                Console.WriteLine(number);
            }
            else if (str=="three")
            {
                number=3;
                Console.WriteLine(number);
            }
            else if (str=="four")
            {
                number=4;
                Console.WriteLine(number);
            }
            else if (str=="five")
            {
                number=5;
                Console.WriteLine(number);
            }
            else if (str=="six")
            {
                number=6;
                Console.WriteLine(number);
            }
            else if (str=="seven")
            {
                number=7;
                Console.WriteLine(number);
            }
            else if (str=="eight")
            {
                number=8;
                Console.WriteLine(number);
            }
            else if (str=="nine")
            {
                number=9;
                Console.WriteLine(number);
            }
            else
            {
                Console.WriteLine("Mistake");
            }

        }

        private static void SolveTask3()
        {
            International_passport rab = new International_passport();
            rab.GetInfo();
            rab.Setifo();
            Console.ReadKey();
        }
        class International_passport
        {
            private string surname;
            private string name;
            private string patronymic;
            private int passport_number;
            private string date_of_issue;
            public void GetInfo()
            {
                Console.WriteLine("Enter your last name");
                surname = Console.ReadLine();
                Console.WriteLine("Enter a name");
                name = Console.ReadLine();
                Console.WriteLine("Enter your middle name");
                patronymic = Console.ReadLine();
                Console.WriteLine("Enter your passport number");
                passport_number =Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Enter the date of issue");
                date_of_issue =Console.ReadLine();
                Console.WriteLine();
            }

            public void Setifo()
            {
                Console.WriteLine("Surname: {0} " +
                    "\t\nName: {1}"+
                    "\t\nPatronymic: {2}"+
                    "\t\nPassport number: {3}"+
                    "\t\nDate of issue: {4}",
                    surname,
                    name,
                    patronymic,
                    passport_number,
                    date_of_issue);
            }
        }
        private static void SolveTask4()
        {
            
            Console.WriteLine("Для выхода из программы введите пустое выражение.");
            for (; ; )
            {
                Console.Write("Введите математическое выражение: ");
                string Nach = Console.ReadLine();
                if (Nach == "") break;
                Console.WriteLine("{0} = {1}", Nach, Scet(Nach));
            }
        }

        static public double Scet(string a)
        {
            int found0 = a.LastIndexOf("<");
            if (found0 >= 0)


                 return Scet(a.Substring(0, found0)) - Scet(a.Substring(found0 + 1));

                

            int found1 = a.LastIndexOf(">");
            if (found1 >= 0)



                return Scet(a.Substring(0, found1)) - Scet(a.Substring(found1 + 1));


            int found2 = a.LastIndexOf("<=");
            if (found2 >= 0)
                return Scet(a.Substring(0, found2)) - Scet(a.Substring(found2 + 1));
            int found3 = a.LastIndexOf(">=");
            if (found3 >= 0)
                return Scet(a.Substring(0, found3)) - Scet(a.Substring(found3 + 1));
            int found4 = a.LastIndexOf("!=");
            if (found4 >= 0)
                return Scet(a.Substring(0, found4)) - Scet(a.Substring(found4 + 1));

            int i = Convert.ToInt32(a);
            Console.WriteLine(i);
            if (i>0)
            {
                Console.WriteLine("true");
            }
            else
            {
                Console.WriteLine("false");
            }
            return Convert.ToInt32(a);
            
           
        }
    

    
    




        
        
        private static int ParseSingleNumberArgument(string[] args)
        {
            if (args.Length != 1)
                throw new ApplicationException("args.Length != 1");

            return int.Parse(args[0]);
        }
    }
}




