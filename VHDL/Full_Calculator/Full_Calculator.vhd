LIBRARY ieee;
USE ieee.STD_LOGIC_1164.all;
USE ieee.numeric_std.all;

ENTITY Full_Calculator IS
	PORT (IN_A,IN_B					:IN STD_LOGIC_VECTOR(3 DOWNTO 0);
			IN_Op					:IN STD_LOGIC_VECTOR(1 DOWNTO 0);
			OUT_HEX3,OUT_HEX2,OUT_HEX1,OUT_HEX0	:OUT STD_LOGIC_VECTOR(6 DOWNTO 0));
END Full_Calculator;

ARCHITECTURE structural of Full_Calculator IS
SIGNAL calc1 :STD_LOGIC_VECTOR(7 DOWNTO 0);
COMPONENT calculator IS
	PORT(A,B					:IN STD_LOGIC_VECTOR(3 DOWNTO 0);
			OP					:IN STD_LOGIC_VECTOR(1 DOWNTO 0);
		   R					:OUT STD_LOGIC_VECTOR(7 DOWNTO 0));
END COMPONENT;

COMPONENT Display IS
	PORT(In_num						:IN STD_LOGIC_VECTOR(7 DOWNTO 0);
			HEX3,HEX2,HEX1,HEX0	:OUT STD_LOGIC_VECTOR(6 DOWNTO 0));
END COMPONENT;

BEGIN
	Calc: calculator
		PORT MAP(A		=>IN_A,
					B		=>IN_B,
					Op		=>IN_Op,
					R		=>calc1);
	Calc2: Display
		PORT MAP(In_num	=>calc1,
					HEX3		=>OUT_HEX3,
					HEX2		=>OUT_HEX2,
					HEX1		=>OUT_HEX1,
					HEX0		=>OUT_HEX0);
END structural;