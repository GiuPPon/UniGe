namespace Esercizio3;
using Moq;
using Xunit.Sdk;
using System.Collections;
using Microsoft.VisualBasic;
using Esercizio1;

public class UnitTest1
{
    //sbagliati

    [Fact]
    public void Test1()
    {
        var source = new int[]{10,20,30,40};
        var moq = new Mock<Func<int, bool>>();
        var service = source.TakeAccepted(x => x/1 == 0, 2).ToList();
        moq.Verify(service => service(2), Times.Exactly(2));
    }

    [Fact]
    public void Test2()
    {
        var source = new int[]{11,22,33,44,55};
        var moq = new Mock<Func<int, bool>>();
        var service = source.TakeAccepted(x => x % 2 != 0, 5).ToList();
        moq.Verify(service => service(3), Times.Exactly(3));
    }

    [Theory]
    [InlineData(4,3,1)]
    [InlineData(5,2,0)]
    [InlineData(6,5,4)]
    public void TakeAcceptedInfiniteTest(int howMany, int divisor, int remainder)
    {
        static IEnumerable<int> infinita()
        {
            int i = 0;
            while(true)
                yield return i++;
        }
        
        var result = infinita().TakeAccepted(x => x % divisor == remainder, howMany).ToArray();
        Assert.Equal([1,4,7,10], result);
        Assert.Equal([2,4,6,8,10], result);
        Assert.Equal([20], result);
    }
}
