--MATTHEW CHU
--timer.vhd
--11/7/2018
--main code
LIBRARY ieee;
USE ieee.STD_LOGIC_1164.all;
USE ieee.numeric_std.all;

ENTITY timer IS
	PORT (Set_n,S,Clk,Reset_n:	IN STD_LOGIC;
			Pre_time:									IN STD_LOGIC_VECTOR(9 DOWNTO 0);
			HEX0,HEX1,HEX2,HEX3:				OUT STD_LOGIC_VECTOR(6 DOWNTO 0));
END timer;

ARCHITECTURE hierarchal of timer IS
	SIGNAL flag,enable   :STD_LOGIC;
	SIGNAL count	  :STD_LOGIC_VECTOR(9 DOWNTO 0);
	SIGNAL max_value  :STD_LOGIC_VECTOR(15 DOWNTO 0);
	
	COMPONENT delay_unit IS
	PORT (max : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
			Reset_n,Clk	:IN STD_LOGIC;
			flag  :OUT STD_LOGIC);
	END COMPONENT;	
	COMPONENT counter IS
	PORT (Set_n,Clk,Reset_n,enable:	IN STD_LOGIC;
			Pre_time:					IN STD_LOGIC_VECTOR(9 DOWNTO 0);
			count  :OUT STD_LOGIC_VECTOR (9 DOWNTO 0));
	END COMPONENT;
	COMPONENT binary2ssd IS
	PORT(In_num						:IN STD_LOGIC_VECTOR(9 DOWNTO 0);
	   	HEX3,HEX2,HEX1,HEX0	:OUT STD_LOGIC_VECTOR(6 DOWNTO 0));
	END COMPONENT;
	BEGIN 
		mux:PROCESS(Clk,S,max_value)
		BEGIN
			IF(rising_edge(Clk) and Clk='1') THEN
				IF(S ='0') THEN
					max_value<="0000000000000100"; --(000ns) //5
				ELSE 
					max_value <= "1100001101010000"; --(1ms) //50000
				END IF;
			END IF;
		END PROCESS mux;
		
	du: delay_unit
	PORT MAP(max=>max_value,
			reset_n=>reset_n,
			Clk=>Clk,
			flag=>enable);
	ctr: counter
	PORT MAP(Set_n=>set_n,
			Pre_time=>Pre_time,
			Clk=>Clk,
			reset_n=>reset_n,
			enable=>enable,
			count=>count);
	b2sd: binary2ssd
	PORT MAP(In_num=>count,
			HEX3=>HEX3,
			HEX2=>HEX2,
			HEX1=>HEX1,
			HEX0=>HEX0);
END hierarchal;