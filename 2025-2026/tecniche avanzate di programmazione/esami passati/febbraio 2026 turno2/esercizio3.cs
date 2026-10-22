namespace Esercizio3;
using Esercizio1;
using Moq;

public class UnitTest1
{
    [Theory]
    [InlineData(new int[]{42},2,0)]
    [InlineData(new int[]{1,1,1,2,2},2,4)]
    [InlineData(new int[]{1,1,3,1,1},1,4)]
    public void Test1(int[] source, int maxRep, int expectedCalls)
    {
        var moq = new Mock<IEqualityComparer<int>>();
        moq.Setup(c => c.Equals(It.IsAny<int>(), It.IsAny<int>())).Returns<int,int>((x,y) => x == y);
        source.LimitConsecutive(maxRep,moq.Object).ToList();
        moq.Verify(c => c.Equals(It.IsAny<int>(), It.IsAny<int>()), Times.Exactly(expectedCalls));
    }
}
