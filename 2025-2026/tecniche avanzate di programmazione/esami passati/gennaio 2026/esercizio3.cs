namespace Esercizio3;
using Esercizio1;

public class UnitTest1
{
    [Theory]
    [InlineData(100,5)]
    [InlineData(50,7)]
    [InlineData(1234,11)]
    public void EveryNInfiniteTest(int howMany, int n)
    {
        IEnumerable<int> source()
        {
            int i = 0;
            while(true)
                yield return i++;
        } 
        
        var firstHMR = source().EveryN(n).Take(howMany).ToList();
        for(int i = 0; i < howMany; i++)
            Assert.Equal(firstHMR[i], (i*n));
    }
}
