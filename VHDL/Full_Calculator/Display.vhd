LIBRARY ieee;
USE ieee.STD_LOGIC_1164.all;
USE ieee.numeric_std.all;

ENTITY Display IS
	PORT (In_num					:IN STD_LOGIC_VECTOR(7 DOWNTO 0);
			HEX3,HEX2,HEX1,HEX0	:OUT STD_LOGIC_VECTOR(6 DOWNTO 0));
END Display;

ARCHITECTURE behavior of Display IS
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
	SIGNAL abs_num,hundreds_dig,tens_dig,ones_dig : STD_LOGIC_VECTOR(7 DOWNTO 0);
	SIGNAL neg : SIGNED(7 DOWNTO 0);
BEGIN
	--NEGATIVE SIGN
	negative :PROCESS(In_num,neg)
		BEGIN
			neg <= SIGNED(In_num);
			IF(neg>=0) THEN 
				HEX3 <= BLANK;
			ELSIF(neg<0) THEN
				HEX3 <= DASH;
			ELSE HEX3 <= BLANK;
			END IF;
	END PROCESS negative;
	--ABS VALUE 
	absolute :PROCESS(In_num, abs_num)
		BEGIN
			abs_num <= STD_LOGIC_VECTOR(ABS(SIGNED(In_num)));
	END PROCESS absolute;
	--HUNDREDS
	hundred	:PROCESS(abs_num,hundreds_dig)
		BEGIN
			hundreds_dig <= STD_LOGIC_VECTOR(UNSIGNED (abs_num)/("01100100"));
			IF hundreds_dig = ("00000000") THEN HEX2<= ZERO;
				ELSIF hundreds_dig = ("00000001") THEN HEX2 <= ONE;
				ELSIF hundreds_dig = ("00000010") THEN HEX2 <= TWO;
				ELSE HEX2<= BLANK;
			END IF;
	END PROCESS hundred;
	--TENS
	ten	:PROCESS(abs_num,tens_dig)
		BEGIN
			tens_dig <= STD_LOGIC_VECTOR((UNSIGNED (abs_num) rem "01100100")/"00001010");
			IF tens_dig = ("00000000") THEN HEX1<= ZERO;
				ELSIF tens_dig = ("00000001") THEN HEX1 <= ONE;
				ELSIF tens_dig = ("00000010") THEN HEX1 <= TWO;
				ELSIF tens_dig = ("00000011") THEN HEX1 <= THREE;
				ELSIF tens_dig = ("00000100") THEN HEX1 <= FOUR;
				ELSIF tens_dig = ("00000101") THEN HEX1 <= FIVE;
				ELSIF tens_dig = ("00000110") THEN HEX1 <= SIX;
				ELSIF tens_dig = ("00000111") THEN HEX1 <= SEVEN;
				ELSIF tens_dig = ("00001000") THEN HEX1 <= EIGHT;
				ELSIF tens_dig = ("00001001") THEN HEX1 <= NINE;
				ELSE HEX1<= BLANK;
			END IF;
		END PROCESS ten;
	--ONES
	oneproc	:PROCESS(abs_num,ones_dig)
		BEGIN
			ones_dig <= STD_LOGIC_VECTOR(UNSIGNED (abs_num) rem "00001010");
			IF ones_dig = ("00000000") THEN HEX0<= ZERO;
				ELSIF ones_dig = ("00000001") THEN HEX0 <= ONE;
				ELSIF ones_dig = ("00000010") THEN HEX0 <= TWO;
				ELSIF ones_dig = ("00000011") THEN HEX0 <= THREE;
				ELSIF ones_dig = ("00000100") THEN HEX0 <= FOUR;
				ELSIF ones_dig = ("00000101") THEN HEX0 <= FIVE;
				ELSIF ones_dig = ("00000110") THEN HEX0 <= SIX;
				ELSIF ones_dig = ("00000111") THEN HEX0 <= SEVEN;
				ELSIF ones_dig = ("00001000") THEN HEX0 <= EIGHT;
				ELSIF ones_dig = ("00001001") THEN HEX0 <= NINE;
				ELSE HEX0<= BLANK;
			END IF;
	END PROCESS oneproc;
END behavior;