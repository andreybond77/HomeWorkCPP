using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LessonTasks.Banking;

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
               
                case 2: SolveTask2(); break;
                case 3: SolveTask3(); break;
                case 4: SolveTask4(); break;
                default: Console.WriteLine("Unknown task"); break;
            }

            Console.ReadKey();
        }

        

        private static void SolveTask2()
        {
            DebitCard debitCard = InputDebitCard();

            Console.WriteLine("Choose what you want to do:");
            Console.WriteLine("1. Debit");
            Console.WriteLine("2. Withdraw");
            switch (int.Parse(Console.ReadLine()))
            {
                case 1:
                    Console.WriteLine("How much would you like to debit:");
                    debitCard += new Transfer(InputDecimal());
                    break;
                case 2:
                    Console.WriteLine("How much would you like to withdraw:");
                    debitCard -= new Transfer(InputDecimal());
                    break;
                default:
                    Console.WriteLine($"Unknown action");
                    return;
            }

            Console.WriteLine("You've left your card in this state:");
            Console.WriteLine($"Number: {debitCard.CardNumber}");
            Console.WriteLine($"Balance: {debitCard.Balance}");
        }

        private static void SolveTask3()
        {
            DebitCard debitCardPrototype = InputDebitCard();

            DebitCard cardWithSecret1 = InputSecret(debitCardPrototype);
            DebitCard cardWithSecret2 = InputSecret(debitCardPrototype);

            int comparison = DebitCard.BalanceComparer.Instance.Compare(
                cardWithSecret1, cardWithSecret2);
            if (comparison > 0)
            {
                Console.WriteLine("Card 1 is greater than card 2");
            }
            else if (comparison < 0)
            {
                Console.WriteLine("Card 1 is less than card 2");
            }
            else
            {
                Console.WriteLine("Cards are equal");
            }

            var uniqueCvc = new HashSet<DebitCard>(DebitCard.CvcComparer.Instance) {
                cardWithSecret1,
                cardWithSecret2
            };

            Console.WriteLine($"Unique cvc numbers found: {uniqueCvc.Count}");
        }

        private static void SolveTask4()
        {

        }

        private static DebitCard InputDebitCard()
        {
            Console.WriteLine("Enter your card number:");
            string cardNumber = Console.ReadLine();

            Console.WriteLine("Enter current balance (nothing else matters)");
            decimal balance = InputDecimal();

            var debitCard = new DebitCard(cardNumber, balance);
            return debitCard;
        }

        private static DebitCard InputSecret(DebitCard debitCardPrototype)
        {
            Console.WriteLine("Enter CVC from back of your card:");
            return debitCardPrototype.WithSecret(Console.ReadLine());
        }

        private static decimal InputDecimal()
        {
            return decimal.Parse(Console.ReadLine());
        }
    }
}
