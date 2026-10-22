namespace Esercizio1;

public static class Class1
{
    public static IEnumerable<T> EveryN<T> (this IEnumerable<T> source, int n)
    {
        ArgumentOutOfRangeException.ThrowIfNegativeOrZero(n);
        return Iterator();

        IEnumerable<T> Iterator()
        {
            int index = 0;
            foreach(var item in source)
            {
                if(index % n == 0) 
                    yield return item;
                index++;
            }
        }
    }
}
