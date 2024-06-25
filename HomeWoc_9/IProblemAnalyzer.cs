using System;
using System.Collections.Generic;
using System.Linq;

namespace LessonTasks.Analysing
{
    public interface IProblemAnalyzer
    {
        void Analyze(string token);
        void CollectProblems(ProblemCollector collector);
    }

    public static class ProblemAnalyzerExtensions
    {
        public static IProblemAnalyzer Compose(this IEnumerable<IProblemAnalyzer> problemAnalyzers)
        {
           
            return new Composite(problemAnalyzers);
        }

       
        private class Composite : List<IProblemAnalyzer>, IProblemAnalyzer
        {

            public Composite(IEnumerable<IProblemAnalyzer> children)
                : base(children)
            {
               
            }

            

            public void Analyze(string token)
            {
                for (int i = 0; i < Count; i++)
                {
                    
                    this[i].Analyze(token);
                   
                }
            }

            public void CollectProblems(ProblemCollector collector)
            {
                for (int i = 0; i < Count; i++)
                {
                    this[i].CollectProblems(collector);
                }
            }
        }
    }
}