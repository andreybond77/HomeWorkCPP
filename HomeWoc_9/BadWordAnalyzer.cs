using System.Collections.Generic;
using System.Linq;

namespace LessonTasks.Analysing
{
    public class BadWordAnalyzer : IProblemAnalyzer
    {
        private readonly Dictionary<string, int> _badWords;

        public BadWordAnalyzer(IEnumerable<string> badWords)
        {
            
            this._badWords = badWords.ToDictionary(badWord => badWord, badWord => 0); 
        }

        public void Analyze(string token)
        {
            
            throw new System.NotImplementedException();
        }

        public void CollectProblems(ProblemCollector collector)
        {
            foreach (KeyValuePair<string, int> kvp in _badWords)
            {
                collector(kvp.Key, kvp.Value);
            }
        }
    }
}