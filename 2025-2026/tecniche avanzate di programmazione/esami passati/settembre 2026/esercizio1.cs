using System.Diagnostics;

namespace Esercizio1;

public static class Class1
{
    public static IEnumerable<T> TakeAccepted<T> (this IEnumerable<T> source, Func<T, bool> predicate, int maxAccepted) {
        ArgumentOutOfRangeException.ThrowIfNegative(maxAccepted);
        return Iterator();

        IEnumerable<T> Iterator()
        {
            if(maxAccepted == 0) 
                yield break;

            int count = 0;  
            foreach(var item in source)
            {
                if(count < maxAccepted)
                {
                    if(predicate(item) == true)
                    {
                        yield return item;
                        count ++;
                    }
                }
            }
        }
    }
}
