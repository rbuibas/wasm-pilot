function prime(n)
{
    console.log('etner' + n);
    let i;
    let j;
    let count = 0;

    if (n === 1) {
        // printf("2\n");
        return 1;
    }
    for(i=3;i<=200;i+=2)
    {
        console.log('loop = ' + i);
        let isPrime=1;
        let jMax = Math.round(Math.sqrt(i));
        console.log('jMax = ' + jMax);
        for(j=3;j<=jMax;j+=2)
        {
            if(i%j===0)
            {
                console.log('i = ' + i + 'j = ' + j);
                isPrime=0;
                break;
            }
        }
        if(isPrime)
        {
            if(++count===n)
            {
                return i;
            }
        }
    }
    return 0;
}

function test() {
    console.log('tested good');
}