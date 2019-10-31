LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY phonenumdisplayer IS 
	PORT( x,y,z,w 	   :IN STD_LOGIC;
			c				:OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
			i           :OUT STD_LOGIC_VECTOR(6 DOWNTO 0));
END phonenumdisplayer;

ARCHITECTURE behavioral OF phonenumdisplayer IS
	CONSTANT ZERO	 :STD_LOGIC_VECTOR(6 DOWNTO 0):="1000000";
	CONSTANT ONE	 :STD_LOGIC_VECTOR(6 DOWNTO 0):="1111001";
	CONSTANT TWO 	 :STD_LOGIC_VECTOR(6 DOWNTO 0):="0100100";
	CONSTANT THREE  :STD_LOGIC_VECTOR(6 DOWNTO 0):="0110000";
	CONSTANT FOUR 	 :STD_LOGIC_VECTOR(6 DOWNTO 0):="0011001";
	CONSTANT FIVE 	 :STD_LOGIC_VECTOR(6 DOWNTO 0):="0010010";
	CONSTANT SIX 	 :STD_LOGIC_VECTOR(6 DOWNTO 0):="0000010";
	CONSTANT SEVEN  :STD_LOGIC_VECTOR(6 DOWNTO 0):="1111000";
	CONSTANT EIGHT  :STD_LOGIC_VECTOR(6 DOWNTO 0):="0000000";
	CONSTANT NINE   :STD_LOGIC_VECTOR(6 DOWNTO 0):="0010000";
	CONSTANT DASH   :STD_LOGIC_VECTOR(6 DOWNTO 0):="0111111";
	CONSTANT BLANK  :STD_LOGIC_VECTOR(6 DOWNTO 0):="1111111";
	SIGNAL inputs: STD_LOGIC_VECTOR(3 DOWNTO 0);
BEGIN
	inputs<=x&y&z&w;
	PROCESS(inputs)
		BEGIN
			CASE inputs IS
				WHEN "0000"|"0010"=> c <= SIX;
				WHEN "0001"|"1001"|"1010"=> c <= FOUR;
				--WHEN "0010"=> c <= SIX;
				WHEN "0011"|"0111"=> c <= DASH;
				WHEN "0100"=> c <= THREE;
				WHEN "0101"|"1000"=> c <= ZERO;
				WHEN "0110"=> c <= ONE;
				--WHEN "0111"=> c <= DASH;
				--WHEN "1000"=> c <= ZERO;
				--WHEN "1001"=> c <= FOUR;
				--WHEN "1010"=> c <= FOUR;
				WHEN "1011"=> c <= NINE;
				WHEN OTHERS=> c <= BLANK;
			END CASE;
		
			IF inputs = ("0000") THEN i<= SIX;
				ELSIF inputs = ("0001") THEN i <= FOUR;
				ELSIF inputs = ("0010") THEN i <= SIX;
				ELSIF inputs = ("0011") THEN i <= DASH;
				ELSIF inputs = ("0100") THEN i <= THREE;
				ELSIF inputs = ("0101") THEN i <= ZERO;
				ELSIF inputs = ("0110") THEN i <= ONE;
				ELSIF inputs = ("0111") THEN i <= DASH;
				ELSIF inputs = ("1000") THEN i <= ZERO;
				ELSIF inputs = ("1001") THEN i <= FOUR;
				ELSIF inputs = ("1010") THEN i <= FOUR;
				ELSIF inputs = ("1011") THEN i <= NINE;
				ELSE i<= BLANK;
			END IF;
	END PROCESS;
END behavioral;

