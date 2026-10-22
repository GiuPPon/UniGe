namespace Esercizio1;

public static class Class1
{
    public static IEnumerable<T> TakeThenSkip<T> (this IEnumerable<T> source, int take, int skip)
    {
        ArgumentOutOfRangeException.ThrowIfNegativeOrZero(take);
        ArgumentOutOfRangeException.ThrowIfNegative(skip);
        return Iterator();

        IEnumerable<T> Iterator()
        {
            int TakeCount = 0;
            int SkipCount = 0;
            foreach(var item in source)
            {
                if(TakeCount < take)
                {
                    yield return item;
                    TakeCount++;
                } else if (SkipCount < skip)
                {
                    SkipCount++;
                }
                if(TakeCount == take && SkipCount == skip)
                {
                    TakeCount = 0;
                    SkipCount = 0;
                }
            }
        }
    }
}
