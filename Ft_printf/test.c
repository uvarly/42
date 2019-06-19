#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	void	*ptr;
	ptr = strdup("ab\tc");

//!!!!!!!!!!!!!!!!!!!!
	// printf("sys: %d\n", printf("sys:%+ f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%+ f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:%0100.20f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%0100.20f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:%+ -100.20f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%+ -100.20f|\n", 0.0));
//!!!!!!!!!!!!!!!!!!!!	

	// printf("sys: %d\n", printf("sys:%f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:%+f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%+f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:%-f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%-f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:%10f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%10f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:%+6f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%+6f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:%.f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%.f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:%.1f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%.1f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:%100.20f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%100.20f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:%-100f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%-100f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:%-100.20f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%-100.20f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:%+100.20f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%+100.20f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:%# 6.6f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%# 6.6f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:%-0100.20f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:%-0100.20f|\n", 0.0));
	// printf("sys: %d\n", printf("sys:% 100.20f|\n", 0.0));
	// printf("our: %d\n", ft_printf("our:% 100.20f|\n", 0.0));

	// printf("sys: %d\n", printf("sys:%f|\n", 43545345651167.3745));
	// printf("our: %d\n", ft_printf("our:%f|\n", 43545345651167.3745));
	// printf("sys: %d\n", printf("sys:%+f|\n", 43545345651167.3745));
	// printf("our: %d\n", ft_printf("our:%+f|\n", 43545345651167.3745));
	// printf("sys: %d\n", printf("sys:%-f|\n", 43545345651167.3745));
	// printf("our: %d\n", ft_printf("our:%-f|\n", 43545345651167.3745));
	// printf("sys: %d\n", printf("sys:%10f|\n", 43545345651167.3745));
	// printf("our: %d\n", ft_printf("our:%10f|\n", 43545345651167.3745));
	// printf("sys: %d\n", printf("sys:%+6f|\n", 43545345651167.3745));
	// printf("our: %d\n", ft_printf("our:%+6f|\n", 43545345651167.3745));
	// printf("sys: %d\n", printf("sys:%.f|\n", 43545345651167.3745));
	// printf("our: %d\n", ft_printf("our:%.f|\n", 43545345651167.3745));
	// printf("sys: %d\n", printf("sys:%.1f|\n", 43545345651167.3745));
	// printf("our: %d\n", ft_printf("our:%.1f|\n", 43545345651167.3745));
	// printf("sys: %d\n", printf("sys:%100.20f|\n", 43545345651167.3745));
	// printf("our: %d\n", ft_printf("our:%100.20f|\n", 43545345651167.3745));
	// printf("sys: %d\n", printf("sys:%-50f|\n", 43545345651167.3745));
	// printf("our: %d\n", ft_printf("our:%-50f|\n", 43545345651167.3745));
	// printf("sys: %d\n", printf("sys:%-100.20f|\n", 43545345651167.3745));
	// printf("our: %d\n", ft_printf("our:%-100.20f|\n", 43545345651167.3745));
	// printf("sys: %d\n", printf("sys:%+100.20f|\n", 43545345651167.3745));
	// printf("our: %d\n", ft_printf("our:%+100.20f|\n", 43545345651167.3745));
	// printf("sys: %d\n", printf("sys:%# 6.6f|\n", 43545345651167.3745));
	// printf("our: %d\n", ft_printf("our:%# 6.6f|\n", 43545345651167.3745));
	// printf("sys: %d\n", printf("sys:%-0100.5Lf|\n", 4294967295.868));
	// printf("our: %d\n", ft_printf("our:%-0100.5Lf|\n", 4294967295.868));

	// printf("sys: %d\n", printf("sys:%+0100.5Lf|\n", (long double)-4294967295.868));
	// printf("our: %d\n", ft_printf("our:%+0100.5Lf|\n", (long double)-4294967295.868));

	// printf("sys: %d\n", printf("sys:% -100.5Lf|\n", (long double)4294967295.868));
	// printf("our: %d\n", ft_printf("our:% -100.5Lf|\n", (long double)4294967295.868));

	// printf("sys: %d\n", printf("%sThis is a %sblue text.", RED, NRM));
	// printf("our: %d\n", ft_printf("This is a red number: %s%d.", RED, 42));

	// printf("our: %d\n", ft_printf("our:%d|\n", 34));
	
	// printf("sys: %d\n", printf("sys:%lo, %lo\n", 0, 9223372036854775807));
	// printf("our: %d\n", ft_printf("our:%lo, %lo\n", 0, 9223372036854775807));

	// printf("sys: %d\n", printf("sys:%lo, %lo\n", 0, -2147483648));
	// printf("our: %d\n", ft_printf("our:%lo, %lo\n", 0, -2147483648));
//u
	
	// printf("sys: %d\n", printf("sys:%#03.hhu|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#03.hhu|\n", 0));
	// printf("sys: %d\n",printf("sys:%010.5u|\n", 0));
	// printf("our: %d\n",ft_printf("our:%010.5u|\n", 0));

	// printf("sys: %d\n", printf("sys:%1.u|\n", -4));
	// printf("our: %d\n", ft_printf("our:%1.u|\n", -4));
	// printf("sys: %d\n",printf("sys:%10.u|\n", -4));
	// printf("our: %d\n",ft_printf("our:%10.u|\n", -4));

	// printf("sys: %d\n", printf("sys:%2.d|\n", 0));
	// printf("our: %d\n", ft_printf("our:%2.d|\n", 0));
	// printf("sys: %d\n",printf("sys:%10.d|\n", 0));
	// printf("our: %d\n",ft_printf("our:%10.d|\n", 0));

	// printf("sys: %d\n", printf("sys:%1.d|\n", -4));
	// printf("our: %d\n", ft_printf("our:%1.d|\n", -4));
	// printf("sys: %d\n",printf("sys:%10.d|\n", -4));
	// printf("our: %d\n",ft_printf("our:%10.d|\n", -4));
 	// printf("sys: %d\n", printf("sys:%100.20u|\n", 124141));
	// printf("our: %d\n", ft_printf("our:%100.20u|\n", 124141));
	// printf("sys: %d\n",printf("sys:%-100.20u|\n", 124141));
	// printf("our: %d\n",ft_printf("our:%-100.20u|\n", 124141));
	// printf("sys: %d\n",printf("sys:% -100.20u|\n", 124141));
	// printf("our: %d\n",ft_printf("our:% -100.20u|\n", 124141));
	// printf("sys: %d\n",printf("sys:%+-100.20u|\n", 124141));
	// printf("our: %d\n",ft_printf("our:%+-100.20u|\n", 124141));
	// printf("sys: %d\n",printf("sys:%+-100.20u|\n", -124141));
	// printf("our: %d\n",ft_printf("our:%+-100.20u|\n", -124141));
	// printf("sys: %d\n",printf("sys:%0100.20u|\n", -124141));
	// printf("our: %d\n",ft_printf("our:%0100.20u|\n", -124141));	
	// printf("sys: %d\n",printf("sys:% -30u|\n", -124141));
	// printf("our: %d\n",ft_printf("our:% -30u|\n", -124141));	

	// printf("sys: %d\n", printf("sys:%100.20u|\n", 0));
	// printf("our: %d\n", ft_printf("our:%100.20u|\n", 0));
	// printf("sys: %d\n",printf("sys:%-100.20u|\n", 0));
	// printf("our: %d\n",ft_printf("our:%-100.20u|\n", 0));
	// printf("sys: %d\n",printf("sys:% -100.20u|\n", 0));
	// printf("our: %d\n",ft_printf("our:% -100.20u|\n", 0));
	// printf("sys: %d\n",printf("sys:%+-100.20u|\n", 0));
	// printf("our: %d\n",ft_printf("our:%+-100.20u|\n", 0));
	// printf("sys: %d\n",printf("sys:%+-100.20u|\n", -0));
	// printf("our: %d\n",ft_printf("our:%+-100.20u|\n", -0));
	// printf("sys: %d\n",printf("sys:%0100.20u|\n", -0));
	// printf("our: %d\n",ft_printf("our:%0100.20u|\n", -0));	
	// printf("sys: %d\n",printf("sys:% -30u|\n", -0));
	// printf("our: %d\n",ft_printf("our:% -30u|\n", -0));	

	// printf("our: %d\n",ft_printf("our:%.u|\n", 0));
	// printf("sys: %d\n",printf("sys:%.u|\n", 0));
	// printf("our: %d\n",ft_printf("our:%.u|\n", 123));	
	// printf("sys: %d\n",printf("sys:%.u|\n", 123));
	// printf("our: %d\n",ft_printf("our:% .u|\n", 0));
	// printf("sys: %d\n",printf("sys:% .u|\n", 0));
	// printf("our: %d\n",ft_printf("our:% .u|\n", 123));	
	// printf("sys: %d\n",printf("sys:% .u|\n", 123));
	// printf("our: %d\n",ft_printf("our:%#.u|\n", 0));
	// printf("sys: %d\n",printf("sys:%#.u|\n", 0));
	// printf("our: %d\n",ft_printf("our:%#.u|\n", 123));	
	// printf("sys: %d\n",printf("sys:%#.u|\n", 123));

	// printf("our: %d\n",ft_printf("our:%0100.20u|\n", 0));
	// printf("sys: %d\n",printf("sys:%0100.20u|\n", 0));
	// printf("our: %d\n",ft_printf("our:%-0100.20u|\n", 0));	
	// printf("sys: %d\n",printf("sys:%-0100.20u|\n", 0));
	// printf("our: %d\n",ft_printf("our:%0100.20u|\n", 123));
	// printf("sys: %d\n",printf("sys:%0100.20u|\n", 123));
	// printf("our: %d\n",ft_printf("our:%-0100.20u|\n", 123));	
	// printf("sys: %d\n",printf("sys:%-0100.20u|\n", 123));

	// printf("%20u|\n", 37732);
	// ft_printf("%20u|\n", 37732);
	// printf("%100.20u|\n", 37732);
	// ft_printf("%100.20u|\n", 37732);
	// printf("%0100u|\n", 37732);
	// ft_printf("%0100u|\n", 37732);
	// printf("sys: %d\n",printf("%.20u|\n", 37732));
	// printf("sys: %d\n",ft_printf("%.20u|\n", 37732));



// d

	// printf("sys: %d\n", printf("sys:% +020.10d|\n", -56754));
	// printf("our: %d\n", ft_printf("our:% +020.10d|\n", -56754));
	// printf("sys: %d\n", printf("sys:% +020.10d|\n",0));
	// printf("our: %d\n", ft_printf("our:% +020.10d|\n", 0));
	

	// printf("sys: %d\n", printf("sys:%1.0d|\n", -56754));
	// printf("our: %d\n", ft_printf("our:%1.0d|\n", -56754));
	// printf("sys: %d\n", printf("sys:%10.5d|\n",0));
	// printf("our: %d\n", ft_printf("our:%10.5d|\n", 0));
	// printf("sys: %d\n", printf("sys:%100.20d|\n", 124141));
	// printf("our: %d\n", ft_printf("our:%100.20d|\n", 124141));
	// printf("sys: %d\n",printf("sys:%-100.20d|\n", 124141));
	// printf("our: %d\n",ft_printf("our:%-100.20d|\n", 124141));
	// printf("sys: %d\n",printf("sys:% -100.20i|\n", 124141));
	// printf("our: %d\n",ft_printf("our:% -100.20i|\n", 124141));
	// printf("sys: %d\n",printf("sys:%+-100.20d|\n", 124141));
	// printf("our: %d\n",ft_printf("our:%+-100.20d|\n", 124141));
	// printf("sys: %d\n",printf("sys:%+-100.20d|\n", -124141));
	// printf("our: %d\n",ft_printf("our:%+-100.20d|\n", -124141));
	// printf("sys: %d\n",printf("sys:%0100.20d|\n", -124141));
	// printf("our: %d\n",ft_printf("our:%0100.20d|\n", -124141));	
	// printf("sys: %d\n",printf("sys:% -30d|\n", -124141));
	// printf("our: %d\n",ft_printf("our:% -30d|\n", -124141));	

	// printf("sys:%d|\n", 0);
	// ft_printf("our:%d|\n", 0);
	// printf("sys:%.d|\n", 0);
	// ft_printf("our:%.d|\n", 0);
	// printf("sys:%-.d|\n", 0);
	// ft_printf("our:%-.d|\n", 0);
	// printf("%d\n", 42);
	// ft_printf("%d\n", 42);

	// printf("%d%d\n", 42, 41);
	// ft_printf("%d%d\n", 42, 41);
	// printf("%d%d%d\n", 42, 43, 44);
	// ft_printf("%d%d%d\n", 42, 43, 44);
	// printf("%20.15d|\n", 54321);					
	// ft_printf("%20.15d|\n", 54321);				
	// printf("%-10d|\n", 3);						
	// ft_printf("%-10d|\n", 3);						
	// printf("% d|\n", 3);							
	// ft_printf("% d|\n", 3);						
	// printf("%+d|\n", 3);	
	// ft_printf("%+d|\n", 3);	

	// printf("%010d\n", 1);	
	// ft_printf("%010d\n", 1);	
	// printf("%hhd\n", 0);	
	// ft_printf("%hhd\n", 0);	
	// printf("%ld\n", 2147483647);					
	// ft_printf("%ld\n", 2147483647);				
	// printf("%lld\n", 9223372036854775807);		
	// ft_printf("%lld\n", 9223372036854775807);	
	
	// printf("%.20d|\n", 37732);
	// ft_printf("%.20d|\n", 37732);
	// printf("%20d|\n", 37732);
	// ft_printf("%20d|\n", 37732);
	// printf("%100.20d|\n", 37732);
	// ft_printf("%100.20d|\n", 37732);
	// printf("%0100d|\n", 37732);
	// ft_printf("%0100d|\n", 37732);

	// printf("%5d|\n", -42);
	// ft_printf("%5d|\n", -42);
	// printf("%-5d|\n", -42);
	// ft_printf("%-5d|\n", -42);
	// printf("%05d|\n", -42);
	// ft_printf("%05d|\n", -42);
	// printf("%25.5d|\n", -42);
	// ft_printf("%25.5d|\n", -42);
	// printf("%-25.5d|\n", -42);
	// ft_printf("%-25.5d|\n", -42);

	// printf("%5d|\n", 0);
	// ft_printf("%5d|\n\n", 0);
	// printf("%-5d|\n", 0);
	// ft_printf("%-5d|\n\n", 0);
	// printf("%05d|\n", 0);
	// ft_printf("%05d|\n\n", 0);
	// printf("%25.5d|\n", 0);
	// ft_printf("%25.5d|\n\n", 0);
	// printf("%-25.5d|\n", 0);
	// ft_printf("%-25.5d|\n\n", 0);
	// printf("%5.5d|\n", 0);
	// ft_printf("%5.5d|\n", 0);

	// printf("%.20d|\n", 0);
	// ft_printf("%.20d|\n", 0);
	// printf("%20d|\n", 0);
	// ft_printf("%20d|\n", 0);
	// printf("%100.20d|\n", 0);
	// ft_printf("%100.20d|\n", 0);
	// printf("%0100d|\n", 0);
	// ft_printf("%0100d|\n", 0);


//x 
//!!!!!!!!!!!!!!!!!!
	// printf("sys: %d\n", printf("sys:%1.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%1.x|\n", 0));

	

	// printf("sys: %d\n", printf("sys:%.10x|\n", -2147483648));
	// printf("our: %d\n", ft_printf("our:%.10x|\n", -2147483648));

	// printf("sys: %d\n", printf("sys:@moulitest: %#.x %#.0x\n", 0, 0));
	// printf("our: %d\n", ft_printf("our:@moulitest: %#.x %#.0x\n", 0, 0));
	// printf("sys: %d\n", printf("sys:@moulitest: %.x %.0x\n", 0, 0));
	// printf("our: %d\n", ft_printf("our:@moulitest: %.x %.0x\n", 0, 0));

	// printf("sys: %d\n", printf("sys:%1.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%1.x|\n", 0));
	// printf("sys: %d\n", printf("sys:%10x|\n", 5));
	// printf("our: %d\n", ft_printf("our:%10x|\n", 5));

	// printf("sys: %d\n", printf("sys:%.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%.x|\n", 0));
	// printf("sys: %d\n", printf("sys:%#.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#.x|\n", 0));
	// printf("sys: %d\n", printf("sys:%#.5x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#.5x|\n", 0));
	
	// printf("sys: %d\n", printf("sys:%-1.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-1.x|\n", 0));
	// printf("sys: %d\n", printf("sys:%-.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-.x|\n", 0));


	// printf("sys: %d\n", printf("sys:%-10x|\n", 5));
	// printf("our: %d\n", ft_printf("our:%-10x|\n", 5));

	// printf("sys: %d\n", printf("sys:%-.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-.x|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-.x|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-.x|\n", 45));
	// printf("our: %d\n", ft_printf("our:%#-.x|\n", 45));
	// printf("sys: %d\n", printf("sys:%#-.5x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-.5x|\n", 0));


	// printf("sys: %d\n", printf("sys:%#.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#.x|\n", 0));
	// printf("sys: %d\n", printf("sys:%1.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%1.x|\n", 0));

	// printf("sys: %d\n", printf("sys:%#5.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#5.x|\n", 0));
	// printf("sys: %d\n", printf("sys:%5.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%5.x|\n", 0));
	// printf("sys: %d\n", printf("sys:@moulitest: %#.x %#.0x|\n", 0, 0));
	// printf("our: %d\n", ft_printf("our:@moulitest: %#.x %#.0x|\n", 0, 0));
	// printf("sys: %d\n", printf("sys:@moulitest: %.x %.0x|\n", 0, 0));
	// printf("our: %d\n", ft_printf("our:@moulitest: %.x %.0x|\n", 0, 0));

	

	// printf("sys: %d\n", printf("sys:%-1.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-1.x|\n", 0));
	// printf("sys: %d\n", printf("sys:%-10x|\n", 5));
	// printf("our: %d\n", ft_printf("our:%-10x|\n", 5));

	// printf("sys: %d\n", printf("sys:%-.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-.x|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-.x|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-.5x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-.5x|\n", 0));
	

	// printf("sys: %d\n", printf("sys:%#x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#x|\n", 0));

	// printf("sys: %d\n", printf("sys:%#-.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-.x|\n", 0));

	// printf("sys: %d\n", printf("sys:%-1.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-1.x|\n", 0));

	// printf("sys: %d\n", printf("sys:%#-5.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-5.x|\n", 0));
	// printf("sys: %d\n", printf("sys:%-5.x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-5.x|\n", 0));
	// printf("sys: %d\n", printf("sys:@moulitest: %-#.x %#.0x|\n", 0, 0));
	// printf("our: %d\n", ft_printf("our:@moulitest: %-#.x %#.0x|\n", 0, 0));
	// printf("sys: %d\n", printf("sys:@moulitest: %-.x %.0x|\n", 0, 0));
	// printf("our: %d\n", ft_printf("our:@moulitest: %-.x %.0x|\n", 0, 0));


	// printf("sys: %d\n", printf("sys:%-5x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-5x|\n", 0));
	
	// printf("sys: %d\n", printf("sys:%-5x|\n", 5));
	// printf("our: %d\n", ft_printf("our:%-5x|\n", 5));

	// printf("sys: %d\n", printf("sys:%-#100.20x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-#100.20x|\n", 0));
	
	// printf("sys: %d\n", printf("sys:%-#x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-#x|\n", 0));

	// printf("sys: %d\n", printf("sys:%25x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%25x|\n", 0));
	
	// printf("sys: %d\n", printf("sys:%#100.20x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#100.20x|\n", 0));

	// printf("sys: %d\n", printf("sys:%#0100x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#0100x|\n", 0));


	// printf("sys:%-#.2x|\n", 0);
	// ft_printf("our:%-#.2x|\n", 0);
	// printf("sys:%-#20x|\n", 0);
	// ft_printf("our:%-#20x|\n", 0);
	// printf("sys:%-#100.20x|\n", 0);
	// ft_printf("our:%-#100.20x|\n", 0);
	// printf("sys:%-#0100x|\n", 0);
	// ft_printf("our:%-#0100x|\n", 0);

	// printf("sys: %d\n", printf("sys:%#.5x|\n", 37732));
	// printf("our: %d\n", ft_printf("our:%#.5x|\n", 37732));
	// printf("sys: %d\n", printf("sys:%#20x|\n", 37732));
	// printf("our: %d\n", ft_printf("our:%#20x|\n", 37732));

	// printf("sys: %d\n", printf("sys:%#100.20x|\n", 37732));
	// printf("our: %d\n", ft_printf("our:%#100.20x|\n", 37732));
	
	// printf("sys:%#0100x|\n", 37732);
	// ft_printf("our:%#0100x|\n", 37732);

	// printf("sys: %d\n", printf("sys:%#-030x|\n", -124141));
	// printf("our: %d\n", ft_printf("our:%#-030x|\n", -124141));
	// printf("sys: %d\n", printf("sys:%#-0.30x|\n", -124141));
	// printf("our: %d\n", ft_printf("our:%#-0.30x|\n", -124141));
	// printf("sys: %d\n", printf("sys:%#-030.15x|\n", -124141));
	// printf("our: %d\n", ft_printf("our:%#-030.15x|\n", -124141));
	// printf("sys: %d\n", printf("sys:%#-30x|\n", -124141));
	// printf("our: %d\n", ft_printf("our:%#-30x|\n", -124141));

	// printf("sys: %d\n", printf("sys:%#-030x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-030x|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-0.30x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-0.30x|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-030.15x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-030.15x|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-30x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-30x|\n", 0));

	//  printf("sys:%-x|\n", 0);
	// ft_printf("our:%-x|\n", 0);
	// printf("%.x|\n", 0);
	// ft_printf("%.x|\n", 0);
	// printf("%-.x|\n", 0);
	// ft_printf("%-.x|\n", 0);
	// printf("%x\n", 505);							
	// ft_printf("%x\n", 505);						
	// printf("%X\n", 505);							
	// ft_printf("%X\n", 505);		
	// 	printf("sys: %d\n", printf("sys:%#030x|\n", 15));
	// printf("our: %d\n", ft_printf("our:%#030x|\n", 15));



	
//!!!!!!!!!!!!!!!!!!!

	// printf("sys: %d\n", printf("sys:%1.o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%1.o|\n", 0));
	// printf("sys: %d\n", printf("sys:%10o|\n", 5));
	// printf("our: %d\n", ft_printf("our:%10o|\n", 5));

	// printf("sys: %d\n", printf("sys:%.o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%.o|\n", 0));
	// printf("sys: %d\n", printf("sys:%#.o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#.o|\n", 0));
	// printf("sys: %d\n", printf("sys:%#.5o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#.5o|\n", 0));
	

	// printf("sys: %d\n", printf("sys:%#.o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#.o|\n", 0));
	// printf("sys: %d\n", printf("sys:%1.o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%1.o|\n", 0));

	// printf("sys: %d\n", printf("sys:%#5.o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#5.o|\n", 0));
	// printf("sys: %d\n", printf("sys:%5.o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%5.o|\n", 0));
	// printf("sys: %d\n", printf("sys:@moulitest: %#.o %#.0o|\n", 0, 0));
	// printf("our: %d\n", ft_printf("our:@moulitest: %#.o %#.0o|\n", 0, 0));
	// printf("sys: %d\n", printf("sys:@moulitest: %.o %.0o|\n", 0, 0));
	// printf("our: %d\n", ft_printf("our:@moulitest: %.o %.0o|\n", 0, 0));

	//  printf("sys:%#20o|\n", 0);
	// ft_printf("our:%#20o|\n", 0);

	
	// printf("sys:%#100.20x|\n", 0);
	// ft_printf("our:%#100.20x|\n", 0);
	
	// printf("sys:%#0100o|\n", 0);
	// ft_printf("our:%#0100o|\n", 0);

	// printf("sys: %d\n", printf("sys:%-1.o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-1.o|\n", 0));
	// printf("sys: %d\n", printf("sys:%-10o|\n", 5));
	// printf("our: %d\n", ft_printf("our:%-10o|\n", 5));

	// printf("sys: %d\n", printf("sys:%-.o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-.o|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-.o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-.o|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-.5o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-.5o|\n", 0));
	

	// printf("sys: %d\n", printf("sys:%#-.o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-.o|\n", 0));
	// printf("sys: %d\n", printf("sys:%-1.o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-1.o|\n", 0));

	// printf("sys: %d\n", printf("sys:%#-5.o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-5.o|\n", 0));
	// printf("sys: %d\n", printf("sys:%-5.o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-5.o|\n", 0));
	// printf("sys: %d\n", printf("sys:@moulitest: %-#.o %#.0o|\n", 0, 0));
	// printf("our: %d\n", ft_printf("our:@moulitest: %-#.o %#.0o|\n", 0, 0));
	// printf("sys: %d\n", printf("sys:@moulitest: %-.o %.0o|\n", 0, 0));
	// printf("our: %d\n", ft_printf("our:@moulitest: %-.o %.0o|\n", 0, 0));

	//  printf("sys:%-#20o|\n", 0);
	// ft_printf("our:%-#20o|\n", 0);
	// printf("sys:%#-100.6o|\n", 0);
	// ft_printf("our:%#-100.6o|\n", 0);
	// printf("sys:%100.6o|\n", 0);
	// ft_printf("our:%100.6o|\n", 0);
	// printf("sys:%-#0100o|\n", 0);
	// ft_printf("our:%-#0100o|\n", 0);

	// printf("sys:%-#.2o|\n", 0);
	// ft_printf("our:%-#.2o|\n", 0);
	// printf("sys:%-#20o|\n", 0);
	// ft_printf("our:%-#20o|\n", 0);
	// printf("sys:%-#100.20o|\n", 0);
	// ft_printf("our:%-#100.20o|\n", 0);
	// printf("sys:%-#0100o|\n", 0);
	// ft_printf("our:%-#0100o|\n", 0);

	// printf("sys:%#-025.o|\n", 0);
	// ft_printf("our:%#-025.o|\n", 0);
	// printf("sys:%#20o|\n", 214748364);
	// ft_printf("our:%#20o|\n", 214748364);
	// printf("sys:%#100.20o|\n", 214748364);
	// ft_printf("our:%#100.20o|\n", 214748364);
	// printf("sys:%#0100o|\n", 214748364);
	// ft_printf("our:%#0100o|\n", 214748364);

	// printf("sys: %d\n", printf("sys:%#-030o|\n", -124141));
	// printf("our: %d\n", ft_printf("our:%#-030o|\n", -124141));
	// printf("sys: %d\n", printf("sys:%-.5o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%-.5o|\n",0));
	// printf("sys: %d\n", printf("sys:%#-030.15o|\n", -124141));
	// printf("our: %d\n", ft_printf("our:%#-030.15o|\n", -124141));
	// printf("sys: %d\n", printf("sys:%#-30o|\n", -124141));
	// printf("our: %d\n", ft_printf("our:%#-30o|\n", -124141));

	// printf("sys: %d\n", printf("sys:%#-030o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-030o|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-0.30o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-0.30o|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-030.15o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-030.15o|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-30o|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-30o|\n", 0));

	// printf("sys:%#.20x|\n", 0);
	// ft_printf("our:%#.20x|\n", 0);


	// printf("sys:%#20x|\n", 0);
	// ft_printf("our:%#20x|\n", 0);
	
	// printf("sys:%#100.20x|\n", 0);
	// ft_printf("our:%#100.20x|\n", 0);
	// printf("sys:%#0100x|\n", 0);
	// ft_printf("our:%#0100x|\n\n", 0);
	// printf("sys:%-#.20x|\n", 0);
	// ft_printf("our:%-#.20x|\n", 0);
	// printf("sys:%-#20x|\n", 0);
	// ft_printf("our:%-#20x|\n", 0);
	// printf("sys:%-#100.20x|\n", 0);
	// ft_printf("our:%-#100.20x|\n", 0);
	// printf("sys:%#-0100x|\n", 0);
	// ft_printf("our:%#-0100x|\n\n", 0);

	

	// printf("sys: %d\n", printf("sys:%#-030x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-030x|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-0.30x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-0.30x|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-030.15x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-030.15x|\n", 0));
	// printf("sys: %d\n", printf("sys:%#-30x|\n", 0));
	// printf("our: %d\n", ft_printf("our:%#-30x|\n", 0));

	// printf("sys:%d\n", printf("sys:@moulitest: %#.o|\n", 0));
	// printf("our:%d\n", ft_printf("our:@moulitest: %#.o|\n", 0));

	// printf("sys:%d\n", printf("sys:@moulitest: %#.o|\n", 1));
	// printf("our:%d\n", ft_printf("our:@moulitest: %#.o|\n", 1));

	// printf("sys:%-x|\n", 0);
	// ft_printf("our:%-x|\n", 0);
	// printf("%.x|\n", 0);
	// ft_printf("%.x|\n", 0);
	// printf("%-.x|\n", 0);
	// ft_printf("%-.x|\n", 0);
	// printf("%x\n", 505);							
	// ft_printf("%x\n", 505);						
	// printf("%X\n", 505);							
	// ft_printf("%X\n", 505);		
	//

	// printf("%.o|\n", 0);
	// ft_printf("%.o|\n", 0);
	// printf("%-.o|\n", 0);
	// ft_printf("%-.o|\n", 0);
	// printf("sys:%-o|\n", 0);
	// ft_printf("our:%-o|\n", 0);
	

	
	// printf("%-.u|\n", 0);
	// ft_printf("%-.u|\n", 0);
	// printf("%.u|\n", 0);
	// ft_printf("%.u|\n", 0);
	// printf("%u|\n", 0);
	// ft_printf("%u|\n", 0);
	

	
	
					
		
	

	//	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  //
					//	--    <не готовый функционал>    --//
	// printf("%jd\n", 9223372036854775807);
	// ft_printf("%jd\n", 9223372036854775807);
	// printf("%zd\n", 4294967295);
	// ft_printf("%zd\n", 4294967295);
	// printf("%U\n", 4294967295);
	// ft_printf("%U\n", 4294967295);
					//	--    </не готовый функционал>    --//
	//	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  //

	// printf("%\n");					//	!!!
	// ft_printf("%\n");				//	!!!
	// printf("%u\n", 4294967295);
	// ft_printf("%u\n", 4294967295);
	// printf("%o\n", 40);
	// ft_printf("%o\n", 40);
	// printf("%x\n", 1000);
	// ft_printf("%x\n", 1000);
	// printf("%#X\n", 1000);
	// ft_printf("%#X\n", 1000);

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
	// ft_printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
	// printf("%hhd\n", 127 + 42);
	// ft_printf("%hhd\n", 127 + 42);
	// printf("{%03.2d}\n", 0);
	// ft_printf("{%03.2d}\n", 0);
	// printf("%o, %ho, %hho\n", -42, -42, -42);
	// ft_printf("%o, %ho, %hho\n", -42, -42, -42);
	// printf("%hhu, %hhu\n", 0, 127 + 42);
	// ft_printf("%hhu, %hhu\n", 0, 127 + 42);
	// printf("@moulitest: %5.o %5.0o|\n", 0, 0);
	// ft_printf("@moulitest: %5.o %5.0o|\n", 0, 0);
	// printf("%5.0o|\n", 0);
	// ft_printf("%5.0o|\n", 0);
	// printf("@moulitest: %5.d %5.0d|\n", 0, 0);
	// ft_printf("@moulitest: %5.d %5.0d|\n", 0, 0);
// 	printf("%s|%s|%s|\n", "aaaaaaaaaaaaa", "bbbbbbbbbbb", "ccccccccccc");
// 	ft_printf("%s|%s|%s|\n", "aaaaaaaaaaaaa", "bbbbbbbbbbb", "ccccccccccc");
// 	printf("%c|%c|%c|\n", 'c', 'b', 'd');
// 	ft_printf("%c|%c|%c|\n", 'c', 'b', 'd'); 
// 	char *string;
// 	printf("%s %s|\n", NULL, string);
// 	ft_printf("%s %s|\n", NULL, string); 
// 	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11



// 	printf("sys: %d\n", printf("sys:%s|\n", "aaabbbcccddd"));
// 	printf("our: %d\n", ft_printf("our:%s|\n", "aaabbbcccddd"));
// 	printf("sys: %d\n", printf("sys:%#.2s|\n", "aaabbbcccddd"));
// 	printf("our: %d\n", ft_printf("our:%#.2s|\n", "aaabbbcccddd"));
// 	printf("sys: %d\n", printf("sys:%#1s|\n", "aaabbbcccddd"));
// 	printf("our: %d\n", ft_printf("our:%#1s|\n", "aaabbbcccddd"));
// 	printf("sys: %d\n", printf("sys:%100.20s|\n", "aaabbbcccddd"));
// 	printf("our: %d\n", ft_printf("our:%100.20s|\n", "aaabbbcccddd"));
// 	printf("sys: %d\n", printf("sys:%#0100s|\n", "aaabbbcccddd"));
// 	printf("our: %d\n", ft_printf("our:%#0100s|\n", "aaabbbcccddd"));
// 	printf("sys: %d\n", printf("sys:%#-100.20s|\n", "aaabbbcccddd"));
// 	printf("our: %d\n", ft_printf("our:%#-100.20s|\n", "aaabbbcccddd"));
// 	printf("sys: %d\n", printf("sys:%.s|\n", "aaabbbcccddd"));
// 	printf("our: %d\n", ft_printf("our:%.s|\n", "aaabbbcccddd"));

// 	printf("sys: %d\n", printf("sys:%s|\n", "морковка"));
// 	printf("our: %d\n", ft_printf("our:%s|\n", "морковка"));
// 	printf("sys: %d\n", printf("sys:%#.2s|\n", "морковка"));
// 	printf("our: %d\n", ft_printf("our:%#.2s|\n", "морковка"));
// 	printf("sys: %d\n", printf("sys:%#1s|\n", "морковка"));
// 	printf("our: %d\n", ft_printf("our:%#1s|\n", "морковка"));
// 	printf("sys: %d\n", printf("sys:%#100.20s|\n", "морковка"));
// 	printf("our: %d\n", ft_printf("our:%#100.20s|\n", "морковка"));
// 	printf("sys: %d\n", printf("sys:%#0100s|\n", "морковка"));
// 	printf("our: %d\n", ft_printf("our:%#0100s|\n", "морковка"));
// 	printf("sys: %d\n", printf("sys:%#-100.20s|\n", "морковка"));
// 	printf("our: %d\n", ft_printf("our:%#-100.20s|\n", "морковка"));
// 	printf("sys: %d\n", printf("sys:%.s|\n", "морковка"));
// 	printf("our: %d\n", ft_printf("our:%.s|\n", "морковка"));

// 	printf("sys: %d\n", printf("sys:%0.20s|\n", "морковка"));
// 	printf("our: %d\n", ft_printf("our:%0.20s|\n", "морковка"));

// 	printf("sys: %d\n", printf("sys:%s|\n", NULL));
// 	printf("our: %d\n", ft_printf("our:%s|\n", NULL));
// 	printf("sys: %d\n", printf("sys:%20.20s|\n", NULL));
// 	printf("our: %d\n", ft_printf("our:%20.20s|\n", NULL));
// 	printf("sys: %d\n", printf("sys:%10.2s|\n", NULL));
// 	printf("our: %d\n", ft_printf("our:%10.2s|\n", NULL));
// 	printf("sys: %d\n", printf("sys:%#.s|\n", NULL));
// 	printf("our: %d\n", ft_printf("our:%#.s|\n", NULL));

// 	printf("sys: %d\n", printf("sys:%100.20s|\n", NULL));
// 	printf("our: %d\n", ft_printf("our:%100.20s|\n", NULL));
// 	printf("sys: %d\n", printf("sys:%#0100s|\n", NULL));
// 	printf("our: %d\n", ft_printf("our:%#0100s|\n", NULL));
	

// 	printf("sys: %d\n", printf("sys:%-s|\n", NULL));
// 	printf("our: %d\n", ft_printf("our:%-s|\n", NULL));
// 	printf("sys: %d\n", printf("sys:%-.2s|\n", NULL));
// 	printf("our: %d\n", ft_printf("our:%-.2s|\n", NULL));
// 	printf("sys: %d\n", printf("sys:%-.s|\n", NULL));
// 	printf("our: %d\n", ft_printf("our:%-.s|\n", NULL));
// 	printf("sys: %d\n", printf("sys:%-#1s|\n", NULL));
// 	printf("our: %d\n", ft_printf("our:%-#1s|\n", NULL));
// 	printf("sys: %d\n", printf("sys:%-100.20s|\n", NULL));
// 	printf("our: %d\n", ft_printf("our:%-100.20s|\n", NULL));
// 	printf("sys: %d\n", printf("sys:%#-0100s|\n", NULL));
// 	printf("our: %d\n", ft_printf("our:%#-0100s|\n", NULL));
// 	printf("sys: %d\n", printf("sys:%#-100.2s|\n", NULL));
// 	printf("our: %d\n", ft_printf("our:%#-100.2s|\n", NULL));

// 		printf("%100.20s|\n", "aaabbbcccddd");
// 	ft_printf("%100.20s|\n", "aaabbbcccddd");
// 	printf("%-100.20s|\n", "aaabbbcccddd");
// 	ft_printf("%-100.20s|\n", "aaabbbcccddd");
// 	printf("% -100.20s|\n", "aaabbbcccddd");
// 	ft_printf("% -100.20s|\n", "aaabbbcccddd");
// 	printf("%+-100.20s|\n", "aaabbbcccddd");
// 	ft_printf("%+-100.20s|\n", "aaabbbcccddd");
// 	printf("%+-100.20s|\n", "aaabbbcccddd");
// 	ft_printf("%+-100.20s|\n", "aaabbbcccddd");


// 	printf("sys: %d\n", printf("sys:%c|\n", 'c'));
// 	printf("our: %d\n", ft_printf("our:%c|\n", 'c'));
// 	printf("sys: %d\n", printf("sys:%.c|\n", 'c'));
// 	printf("our: %d\n", ft_printf("our:%.c|\n", 'c'));
// 	printf("sys: %d\n", printf("sys:% -c|\n", 'c'));
// 	printf("our: %d\n", ft_printf("our:% -c|\n", 'c'));
// 	printf("sys: %d\n", printf("sys:%- .c|\n", 'c'));
// 	printf("our: %d\n", ft_printf("our:%- .c|\n", 'c'));

// 	printf("sys: %d\n", printf("sys:%.2c|\n", 'c'));
// 	printf("our: %d\n", ft_printf("our:%.2c|\n", 'c'));
// 	printf("sys: %d\n", printf("sys:%#1c|\n", 'c'));
// 	printf("our: %d\n", ft_printf("our:%#1c|\n", 'c'));
// 	printf("sys: %d\n", printf("sys:%100.20c|\n", 'c'));
// 	printf("our: %d\n", ft_printf("our:%100.20c|\n", 'c'));
// 	printf("sys: %d\n", printf("sys:%-.2c|\n", 'c'));
// 	printf("our: %d\n", ft_printf("our:%-.2c|\n", 'c'));
// 	printf("sys: %d\n", printf("sys:%-100.2c|\n", 'c'));
// 	printf("our: %d\n", ft_printf("our:%-100.2c|\n", 'c'));

// 	printf("sys: %d\n", printf("sys:%20c|\n", 'c'));
// 	printf("our: %d\n", ft_printf("our:%20c|\n", 'c'));
// 	printf("sys: %d\n", printf("sys:%-20.c|\n", 'c'));
// 	printf("our: %d\n", ft_printf("our:%-20.c|\n", 'c'));
// 	printf("sys: %d\n", printf("sys:% #c|\n", 'c'));
// 	printf("our: %d\n", ft_printf("our:% #c|\n", 'c'));
// 	printf("sys: %d\n", printf("sys:%.c|\n", 'c'));
// 	printf("our: %d\n", ft_printf("our:%.c|\n", 'c'));

// 	printf("%100.20c|\n", 'c');
// 	ft_printf("%100.20c|\n", 'c');
// 	printf("%-100.20c|\n", 'c');
// 	ft_printf("%-100.20c|\n", 'c');
// 	printf("% -100.20c|\n", 'c');
// 	ft_printf("% -100.20c|\n", 'c');
// 	printf("%+-100.20c|\n", 'c');
// 	ft_printf("%+-100.20c|\n", 'c');
// 	printf("%+-100.20c|\n", 'c');
// 	ft_printf("%+-100.20c|\n", 'c');
// 	printf("%.2c", NULL);
// 	ft_printf("%.2c", NULL);

// 	printf("{%05.c}\n", 0);
// 	ft_printf("{%05.c}\n", 0);
// 	printf("{%05.s}\n", 0);
// 	ft_printf("{%05.s}\n", 0);
// 	printf("{%05.s}\n", "this");
// 	ft_printf("{%05.s}\n", "this");
// 	printf("{%05.d}\n", 0);
// 	ft_printf("{%05.d}\n", 0); 

// 		printf("sys:%d\n", printf("%"));
// 		printf("our:%d\n", ft_printf("%"));
// 		printf("sys:%d\n", printf("%%|\n"));
// 		printf("our:%d\n", ft_printf("%%|\n"));


// 	printf("%5.2s is a string|\n", "this");
// 	ft_printf("%5.2s is a string|\n", "this");
// 	printf("%-5.2s is a string|\n", "this");
// 	ft_printf("%-5.2s is a string|\n", "this");
// 	printf("%5s is a string|\n", "this");
// 	ft_printf("%5s is a string|\n", "this");
// 	printf("%-5s is a string|\n", "this");
// 	ft_printf("%-5s is a string|\n", "this");

// 	printf("%-10s is a string|\n", "");
// 	ft_printf("%-10s is a string|\n", "");
// 	printf("%-.2s is a string|\n", "");
// 	ft_printf("%-.2s is a string|\n", "");
// 	printf("%-5.2s is a string|\n", "");
// 	ft_printf("%-5.2s is a string|\n", "");
// 	printf("@moulitest: %s|\n", NULL);
// 	ft_printf("@moulitest: %s|\n", NULL);

// !!!!!!!!!!!!!!!!!!!	
// 	printf("@main_ftprintf: |%####0000 33..1..#00d\\n|\n", 256);
// 	ft_printf("@main_ftprintf: |%####0000 33..1..#00d\\n|\n", 256);

// //p

// 	ptr = strdup("abc");

		// printf("%p\n", &ft_printf);					
	// ft_printf("%p\n", &ft_printf);		
	// printf("sys: %d\n", printf("%.p, %.0p\n", 0, 0));
	// printf("our: %d\n", ft_printf("%.p, %.0p\n", 0, 0));
	// printf("own:%d\n", ft_printf("own:%p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:%-p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%-p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:% p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:% p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:%#p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%#p|\n", NULL));

	// printf("own:%d\n", ft_printf("own:%p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:%-p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%-p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:% p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:% p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:%#p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%#p|\n", ptr));

	// printf("own:%d\n", ft_printf("own:%.p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%.p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:%-.p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%-.p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:% .p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:% .p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:%#.p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%#.p|\n", NULL));

	// printf("own:%d\n", ft_printf("own:%.p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%.p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:%-.p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%-.p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:% .p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:% .p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:%#.p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%#.p|\n", ptr));

	// printf("own:%d\n", ft_printf("own:%.4p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%.4p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:%-.2p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%-.2p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:% .2p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:% .2p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:%#.2p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%#.2p|\n", NULL));

	// printf("own:%d\n", ft_printf("own:%.2p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%.2p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:%-.2p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%-.2p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:% .2p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:% .2p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:%#.2p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%#.2p|\n", ptr));

	// printf("own:%d\n", ft_printf("own:%4p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%4p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:%20p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%20p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:%-4p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%-4p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:%-20p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%-20p|\n", NULL));

	// printf("own:%d\n", ft_printf("own:%4p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%4p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:%20p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%20p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:%-4p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%-4p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:%-20p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%-20p|\n", ptr));

	// printf("own:%d\n", ft_printf("own:%040.20p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%040.20p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:%020.20p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%020.20p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:%0-40.20p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%0-40.20p|\n", ptr));
	// printf("own:%d\n", ft_printf("own:%0-20.20p|\n", ptr));
	// printf("sys:%d\n",    printf("sys:%0-20.20p|\n", ptr));

	// printf("own:%d\n", ft_printf("own:%040.20p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%040.20p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:%020.20p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%020.20p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:%0-40.20p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%0-40.20p|\n", NULL));
	// printf("own:%d\n", ft_printf("own:%0-20.20p|\n", NULL));
	// printf("sys:%d\n",    printf("sys:%0-20.20p|\n", NULL));

	// char	c[] = "sdfds";
	// printf("%p\n", c);
	// ft_printf("%p\n", c);
	// printf("%p\n", "sddfgsd");
	// ft_printf("%p\n", "sddfgsd");

	long double	num;

// 	printf("sys: |%-+25.f|\n", -2.6);
// 	ft_printf("own: |%-+25.f|\n\n", -2.6);
// 	printf("sys: |%-+25.f|\n", 2.6);
// 	ft_printf("own: |%-+25.f|\n\n", 2.6);
// 	printf("sys: |%-+25.f|\n", -2.5);
// 	ft_printf("own: |%-+25.f|\n\n", -2.5);
// 	printf("sys: |%-+25.f|\n", 2.5);
// 	ft_printf("own: |%-+25.f|\n\n", 2.5);
// 	printf("sys: |%+25.f|\n", -2.4);
// 	ft_printf("own: |%+25.f|\n\n", -2.4);
// 	printf("sys: |%+25.f|\n", 2.4);
// 	ft_printf("own: |%+25.f|\n\n", 2.4);
// 	printf("sys: |%+25.f|\n", -2.0);
// 	ft_printf("own: |%+25.f|\n\n", -2.0);
// 	printf("sys: |%+25.f|\n", 2.0);
// 	ft_printf("own: |%+25.f|\n\n", 2.0);
// 	printf("sys: |%+25.f|\n", 3.6);
// 	ft_printf("own: |%+25.f|\n\n", 3.6);
// 	printf("sys: |%+25.f|\n", -3.6);
// 	ft_printf("own: |%+25.f|\n\n", -3.6);
// 	printf("sys: |%+25.f|\n", 3.5);
// 	ft_printf("own: |%+25.f|\n\n", 3.5);
// 	printf("sys: |%+25.f|\n", -3.5);
// 	ft_printf("own: |%+25.f|\n\n", -3.5);
// 	printf("sys: |%+25.f|\n", 3.4);
// 	ft_printf("own: |%+25.f|\n\n", 3.4);
// 	printf("sys: |%+25.f|\n", -3.4);
// 	ft_printf("own: |%+25.f|\n\n", -3.4);
// 	printf("sys: |%+25.f|\n", 3.0);
// 	ft_printf("own: |%+25.f|\n\n", 3.0);
// 	printf("sys: |%+25.f|\n", -3.0);
// 	ft_printf("own: |%+25.f|\n\n", -3.0);

// 	num = 42.123456789;
// 	printf("sys: |%.Lf|\n", num);
// 	ft_printf("own: |%.Lf|\n\n", num);
// 	num = -42.123456789;
// 	printf("sys: |%.Lf|\n", num);
// 	ft_printf("own: |%.Lf|\n\n", num);
// 	num = 42.123456789;
// 	printf("sys: |%.5Lf|\n", num);
// 	ft_printf("own: |%.5Lf|\n\n", num);
// 	num = -42.123456789;
// 	printf("sys: |%.5Lf|\n", num);
// 	ft_printf("own: |%.5Lf|\n\n", num);
// 	num = 0.0;
// 	printf("sys: |%.5Lf|\n", num);
// 	ft_printf("own: |%.5Lf|\n\n", num);
// 	num = 0.0;
// 	printf("sys: |%.Lf|\n", num);
// 	ft_printf("own: |%.Lf|\n\n", num);
// 	num = 0.5;
// 	printf("sys: |%10.Lf|\n", num);
// 	ft_printf("own: |%10.Lf|\n\n", num);
	
// 	long double flt[100] = {-43.0368744028, 117.2417338859, 178.7870286632, -46.4441833368, -132.3461911261,
// 							-147.8233348698, -169.2465540018, 54.7764062922, -6.3853730505, -120.1786561767,
// 							28.7257899133, 55.4800055835, 154.4606948143, 211.959402035, 82.2080892381,
// 							164.3094426348, -74.4809251728, 69.8401218075, 37.2554918785, 35.793621485,
// 							201.9965671804, -13.4868704916, 84.5430023738, -149.1753851078, 42.3189557867,
// 							24.8292085802, 161.0024678293, -40.0949673439, 61.4804998671, 86.1025186964,
// 							-164.342752549, 14.1357923914, 29.2167878781, -83.5571547139, -38.8960487996,
// 							-63.3497522331, -193.1085881214, 172.140993855, 79.5396851308, 134.4194935227,
// 							-70.2886429151, -182.8485250831, 101.2521545455, -1.3333343879, 81.9514449313,
// 							-110.4758370391, 60.1467595986, -43.8147561261, 177.2279272895, 154.5393495562,
// 							144.134241744, -124.1440100102, 78.8319698334, 202.4216042126, -88.1878785278,
// 							-7.555515426, 114.0199405979, -45.8511394299, -151.2432558989, 189.5344631483,
// 							175.9566669268, -56.6484762051, -77.8072529006, -168.7763467314, -123.043391109,
// 							29.7331557235, 133.5311285628, 80.6981429675, 157.4188980849, 14.4660359195,
// 							130.6229605175, -4.6027955798, 181.1597886473, -145.6238957772, 64.9198194588,
// 							203.0681394586, -158.8024623174, 145.2362099268, 62.8780625467, -120.1410985171,
// 							178.3102388123, -7.7111206696, -38.0493017007, 33.6802946551, -72.2644265379,
// 							203.3026910244, -186.6560382902, 184.2098969231, 114.0626404751, 42.2924729978,
// 							-117.5121597981, -172.239703863, 43.0585484081, -98.5506533797, -43.8403452401,
// 							-171.0290684928, -164.9612135715, 71.3888412869, 31.6308835101, -183.4333329915};
	
// 	for (int i = 1; i < 99; i++)
// 	{
// //		if (flt[i] == 161.0024678293)
// //		{
// 			printf("sys_count: %d\n", printf("sys: |%+70.50Lf|%+70.50Lf|%+70.50Lf|\n", flt[i], flt[i + 1], flt[i - 1]));
// 			printf("own_count: %d\n", ft_printf("own: |%+70.50Lf|%+70.50Lf|%+70.50Lf|\n\n", flt[i], flt[i + 1], flt[i - 1]));
// //		}
// 	}

	// num = 42.123456789;
	// printf("sys_count: %d\n", printf("sys: |%100.5Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |%100.5Lf|\n\n", num));
	// num = -42.123456789;
	// printf("sys_count: %d\n", printf("sys: |%100.Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |%100.Lf|\n\n", num));
	// num = 42.123456789;
	// printf("sys_count: %d\n", printf("sys: |%100.5Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |%100.5Lf|\n\n", num));
	// num = -42.123456789;
	// printf("sys_count: %d\n", printf("sys: |%100.5Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |%100.5Lf|\n\n", num));
	// num = 0.0;
	// printf("sys_count: %d\n", printf("sys: |%100.5Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |%100.5Lf|\n\n", num));
	// num = 0.0;
	// printf("sys_count: %d\n", printf("sys: |%100.Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |%100.Lf|\n\n", num));
	// num = 0.5;
	// printf("sys: |%100.Lf|\n", num);
	// ft_printf("own: |%100.Lf|\n\n", num);

	// num = 42.123456789;
	// printf("sys_count: %d\n", printf("sys: |% .5Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |% .5Lf|\n\n", num));
	// num = -42.123456789;
	// printf("sys: |% .Lf|\n", num);
	// ft_printf("own: |% .Lf|\n\n", num);
	// num = 42.123456789;
	// printf("sys: |% .5Lf|\n", num);
	// ft_printf("own: |% .5Lf|\n\n", num);
	// num = -42.123456789;
	// printf("sys: |% .5Lf|\n", num);
	// ft_printf("own: |% .5Lf|\n\n", num);
	// num = 0.0;
	// printf("sys: |% .5Lf|\n", num);
	// ft_printf("own: |% .5Lf|\n\n", num);
	// num = 0.0;
	// printf("sys: |% .Lf|\n", num);
	// ft_printf("own: |% .Lf|\n\n", num);
	// num = 0.5;
	// printf("sys: |% .Lf|\n", num);
	// ft_printf("own: |% .Lf|\n\n", num);
	// printf("sys_count: %d\n", printf("sys: |%100.Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |%100.Lf|\n\n", num));

	// num = 42.123456789;
	// printf("sys_count: %d\n", printf("sys: |% .5Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |% .5Lf|\n\n", num));
	// num = -42.123456789;
	// printf("sys_count: %d\n", printf("sys: |% .Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |% .Lf|\n\n", num));
	// num = 42.123456789;
	// printf("sys_count: %d\n", printf("sys: |% .5Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |% .5Lf|\n\n", num));
	// num = -42.123456789;
	// printf("sys_count: %d\n", printf("sys: |% .5Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |% .5Lf|\n\n", num));
	// num = 0.0;
	// printf("sys_count: %d\n", printf("sys: |% .5Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |% .5Lf|\n\n", num));
	// num = 0.0;
	// printf("sys_count: %d\n", printf("sys: |% .Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |% .Lf|\n\n", num));
	// num = 0.5;
	// printf("sys_count: %d\n", printf("sys: |% .Lf|\n", num));
	// printf("own_count: %d\n", ft_printf("own: |% .Lf|\n\n", num));

	// printf("sys_count: %d\n", printf("sys: |%-Lf|\n", (long double)INF));
 	// printf("own_count: %d\n", ft_printf("own: |%-Lf|\n\n", (long double)INF));

	// ft_printf("%w\n", "Breaking news: Man dies after overdosing on viagra. His wife took it very hard.");

	#include <fcntl.h>
	#include "../Get_Next_Line/get_next_line.h"

	int fd = open("Makefile", O_RDONLY);
	char *line;
	char *str = NULL;

	while (get_next_line(fd, &line))
	{
		str = !str ? ft_strdup(line) : ft_strjoin(str, line);
	}
	ft_printf("%w\n", str);

	return (0);
}
