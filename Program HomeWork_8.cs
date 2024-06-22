using System;
using System.Collections.Generic;
using System.IO;
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
                default: Console.WriteLine("Unknown task"); break;
            }
        }

       

        private static void SolveTask1()
        {
            Console.WriteLine("Enter task symbol:");
            char symbol_1 = char.Parse(Console.ReadLine());
            Action<char> lambda1 = CreateLambda1();
            Action<char> lambda2 = CreateLambda2();

            Action<char> writeAction = lambda1 + lambda2;

            for (int i = 0; i < 4; i++)
            {
                writeAction(symbol_1);
                Console.WriteLine();
            }
        }

        private static Action<char> CreateLambda1()
        {

            return symbol =>

            {
                for (int i = 0; i < 12; i++)
                {
                    Console.Write(i % 2 == 0 ? symbol :'&');
                }
            };
        }

        private static Action<char> CreateLambda2()
        {
            var random = new Random();
            int counter = 0;
            return symbol =>
            {
                counter++;
                int printIndex = random.Next(0, 4); ;
                for (int i = 0; i < 12; i++)
                {
                    Console.Write(i == printIndex ? symbol : '*');
                }
            };
        }
    }
}
