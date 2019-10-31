--MATTHEW CHU
--delay_unit.vhd
--11/7/2018
--delay unit that determines when counter runs
LIBRARY ieee;
USE ieee.STD_LOGIC_1164.all;
USE ieee.numeric_std.all;

ENTITY delay_unit IS
	PORT (max :IN STD_LOGIC_VECTOR(15 DOWNTO 0);
			Reset_n,Clk	:IN STD_LOGIC;
			flag  :OUT STD_LOGIC);
END delay_unit;

ARCHITECTURE behavioral of delay_unit IS
	SIGNAL count :STD_LOGIC_VECTOR(15 DOWNTO 0);	
BEGIN
	PROCESS(count,max,Reset_n,Clk)
		BEGIN
			IF (Reset_n='0') THEN
					count<="0000000000000000";
			ELSIF(rising_edge(Clk) and Clk='1') THEN
				IF(count=max) THEN
					flag<='1';
					count<="0000000000000000";
				ELSE
					flag<='0';
					count<=STD_LOGIC_VECTOR(UNSIGNED(count)+ 1);
				END IF;
			END IF;
	END PROCESS;
END behavioral;