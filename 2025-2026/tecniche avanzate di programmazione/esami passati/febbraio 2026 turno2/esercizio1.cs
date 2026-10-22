using System.Security.AccessControl;

namespace Esercizio1;

public static class Class1
{
    public static IEnumerable<T> LimitConsecutive<T> (this IEnumerable<T> source, int maxRep, IEqualityComparer<T>? comparer)
    {
        ArgumentOutOfRangeException.ThrowIfNegativeOrZero(maxRep);

        if(comparer == null) 
            comparer = EqualityComparer<T>.Default;

        return Iterator();

        IEnumerable<T> Iterator()
        {
            int count = 0;
            T? prev = default;
            bool First = true;
            foreach(var item in source)
            {
                if (First) // caso primo elemento
                {
                    yield return item;
                    prev = item;
                    count = 1;
                    First = false;
                } else {
                    if (comparer.Equals(prev,item)) // se stesso item viene ripetuto più volte
                    {
                        count++;
                        if(count <= maxRep)
                            yield return item;
                    } else
                    {
                        yield return item;
                        prev = item;
                        count = 1; // se l'elemento non è uguale a prev, riparto con il count da 1
                    }
                }
            }
        }
    }
}

