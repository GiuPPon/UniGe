namespace Esercizio1;

public static class Class1
{
    public static IEnumerable<T> MyTake<T> (this IEnumerable<T> source, int count)
    {
        ArgumentOutOfRangeException.ThrowIfLessThan(count, -1);
        return Iterator();

        IEnumerable<T> Iterator()
        {
            int index = 0;
            foreach(var item in source)
            {
                if(count == 0) 
                    yield break;
                
                if(index < count || count == -1)
                {
                    yield return item;
                    index++;
                }
            }
        }
    }
}
