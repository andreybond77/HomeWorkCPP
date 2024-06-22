﻿

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace LessonTasks
{
    internal static class Program
    {

        private static void Main(string[] args)
        {
            Console.WriteLine("Enter task number:");
            int taskNumber = int.Parse(Console.ReadLine());
            switch (taskNumber)
            {
                case 1: SolveTask1(); break;
               

                default: Console.WriteLine("Unknown task"); break;
            }

            Console.ReadKey();
        }

        private static void SolveTask1()
        {

            try
            {
                SolveTask1Handled();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Ooops.. Something went wrong:");
                Console.WriteLine(ex.Message);
            }
        }

        private static void SolveTask1Handled()
        {
            Console.WriteLine("Enter count of numbers to generate:");
            int countToGenerate = int.Parse(Console.ReadLine());

            Console.WriteLine("Choose one of supported number generators: odd");
            string generatorName = Console.ReadLine();

            OddNumberGenerator numberGenerator;

            switch (generatorName)
            {
                case "odd":
                    numberGenerator = new OddNumberGenerator();
                    break;
                default:
                    throw new ApplicationException($"Unknown generator: {generatorName}");
            }

            for (int i = 0; i < countToGenerate; i++)
            {
                int generatedNumber = numberGenerator.Next();
                Console.WriteLine($"Generated number {i + 1}: {generatedNumber}");
            }

            Console.WriteLine("Press any key to finish...");
        }

    }
}
