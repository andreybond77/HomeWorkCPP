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
            Console.WriteLine("Writing to a file:1");
            Console.WriteLine("Read the file:2");
            
            int taskNumber = int.Parse(Console.ReadLine());
            switch (taskNumber)
            {
                case 1: SolveTask1(); break;
                case 2: SolveTask2(); break;
                default: Console.WriteLine("Unknown task"); break;
            }
        }

        private static void SolveTask1()
        {
            Console.WriteLine("Enter a line to write to the file:");
            string text = Console.ReadLine();

            using (FileStream fstream = new FileStream(@"note.txt", FileMode.OpenOrCreate))
            {
                
                byte[] array = System.Text.Encoding.Default.GetBytes(text);
                fstream.Write(array, 0, array.Length);
                Console.WriteLine("The text is written to a file");
            }

            Console.WriteLine("Read text from a file?:y/n");
            char contr = char.Parse(Console.ReadLine());
            switch (contr)
            {
                case 'y': SolveTask_y(); break;
                case 'n': SolveTask_n(); break;
                default: Console.WriteLine("Unknown task"); break;
            }
        }
        private static void SolveTask_y()
        {
            using (FileStream fstream = File.OpenRead(@"note.txt"))
            {
                byte[] array = new byte[fstream.Length];
                fstream.Read(array, 0, array.Length);
                string textFromFile = System.Text.Encoding.Default.GetString(array);
                Console.WriteLine("Text from the file: {0}", textFromFile);
            }
        }
        private static void SolveTask_n()
        {
            Console.WriteLine("The program is completed");
        }
        private static void SolveTask2()
        {           
            using (FileStream fstream = File.OpenRead(@"note.txt"))
            {               
                byte[] array = new byte[fstream.Length];               
                fstream.Read(array, 0, array.Length);               
                string textFromFile = System.Text.Encoding.Default.GetString(array);
                Console.WriteLine("Text from the file: {0}", textFromFile);
            }

        }
    }
}
