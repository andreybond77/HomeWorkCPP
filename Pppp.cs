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
                case 5: SolveTask5(); break;
                default: Console.WriteLine("Unknown task"); break;
            }


        }
        
           public static void SolveTask1()
            {
                Random myRnd = new Random();
                Console.WriteLine("Enter the number of numbers: ");
                int n = int.Parse(Console.ReadLine());
                Console.WriteLine("Enter the min number: ");
                int min = int.Parse(Console.ReadLine());
                Console.WriteLine("Enter the max number: ");
                int max = int.Parse(Console.ReadLine());
                int[] a = new int[n];

                for (int i = 0; i < a.Length; i++)
                {
                    a[i] = myRnd.Next(min, max);
                    if (a[i] % 2 == 0)
                        Console.WriteLine(a[i]);

                }

            }



        


       
           private static void SolveTask2()
        {
                Random myRnd = new Random();
                Console.WriteLine("Enter the number of numbers: ");
                int n = int.Parse(Console.ReadLine());
                Console.WriteLine("Enter the min number: ");
                int min = int.Parse(Console.ReadLine());
                Console.WriteLine("Enter the max number: ");
                int max = int.Parse(Console.ReadLine());
                int[] a = new int[n];

                for (int i = 0; i < a.Length; i++)
                {
                    a[i] = myRnd.Next(min, max);
                    if (a[i] % 2 != 0)
                        Console.WriteLine(a[i]);

                }

            }



        private static void SolveTask3()
        {

            
            Console.WriteLine("Enter the number of numbers: ");
            int n = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter the min number: ");
            int next = int.Parse(Console.ReadLine());
          
            int prev = 0;
           
            for (int i = 1; i < n; i++)
            {
                int sum = prev + next;
                prev = next;
                next = sum;
                Console.WriteLine(next);
            }          

        }


        private static void SolveTask4()
        {
            Console.WriteLine("The game \"Guess the number\" ");

            Console.Write("Enter the 1st number: ");
            int x = int.Parse(Console.ReadLine());
            Console.Write("Enter the 2st number: ");
            int y = int.Parse(Console.ReadLine());

            Random random = new Random();
            int k = random.Next(x, y);
            int count = 0;
            string str;

            Console.WriteLine("Guess the number in the range from {0} to {1}\n", x, y);

            do
            {
                Console.Write("Your option: ");
                str = Console.ReadLine();

                if (int.Parse(str) < k)
                    Console.WriteLine("The intended number is greater");
                if (int.Parse(str) > k)
                    Console.WriteLine("The intended number is less");

                count++;
            }
            while (int.Parse(str) != k);

            Console.WriteLine("You guessed right on the {0} attempt", count);
            Console.ReadLine();


        }




        public static void SolveTask5()
        {

            Random rand = new Random();
            
            Console.WriteLine("Enter the number of vowel letters: ");
            int stringlen = int.Parse(Console.ReadLine());
          
            int randValue;
            string str = "";
            char letter;
            for (int i = 0; i < stringlen; i++)
            {
 
                randValue = rand.Next(0, 26);

                
                letter = Convert.ToChar(randValue + 65);

                
                str = str + letter;
            }
            Console.Write( str);

        }






        private static int ParseSingleNumberArgument(string[] args)
        {
            if (args.Length != 1)
                throw new ApplicationException("args.Length != 1");

            return int.Parse(args[0]);
        }


    }


}
