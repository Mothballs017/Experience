--MATTHEW CHU
--counter.vhd
--11/7/2018
--counter for the display
LIBRARY ieee;
USE ieee.STD_LOGIC_1164.all;
USE ieee.numeric_std.all;

ENTITY counter IS
	PORT (	Set_n,Clk,Reset_n,enable:	IN STD_LOGIC;
			Pre_time:					IN STD_LOGIC_VECTOR(9 DOWNTO 0);
			count  :OUT STD_LOGIC_VECTOR (9 DOWNTO 0));
END counter;

ARCHITECTURE behavioral of counter IS
SIGNAL int_count :STD_LOGIC_VECTOR(9 DOWNTO 0);
CONSTANT max:STD_LOGIC_VECTOR(9 DOWNTO 0) := "1111100111"; --999
BEGIN	
PROCESS(Clk,Reset_n,Pre_time,Set_n,enable)
		BEGIN
			IF(Reset_n='0') THEN
				int_count<="0000000000";
			ELSIF(Set_n='0') THEN
				int_count <= Pre_time;
			ELSIF(rising_edge(Clk)) THEN
				IF(enable='1') THEN
					IF(int_count=max) THEN
						int_count <= "0000000000";
					ELSE
						int_count <= STD_LOGIC_VECTOR(UNSIGNED(int_count) + 1);
					END IF;
				END IF;
			END IF;
	END PROCESS;
	count<=int_count;
END behavioral;