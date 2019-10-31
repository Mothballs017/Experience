LIBRARY ieee;
USE ieee.STD_LOGIC_1164.all;
USE ieee.numeric_std.all;

ENTITY calculator IS
	PORT (A,B				:IN STD_LOGIC_VECTOR(3 DOWNTO 0);
			OP					:IN STD_LOGIC_VECTOR(1 DOWNTO 0);
		   R					:OUT STD_LOGIC_VECTOR(7 DOWNTO 0));
END calculator;

ARCHITECTURE behavior of calculator IS
	SIGNAL A_signed,B_signed: SIGNED(3 DOWNTO 0);
BEGIN
	calc :PROCESS(A,B,OP,A_signed,B_signed)
		BEGIN
			A_signed<= SIGNED(A);
			B_signed<= SIGNED(B);
			CASE OP IS 
				WHEN "00" => R <= STD_LOGIC_VECTOR((A_signed(3) & A_signed(3) & A_signed(3) & A_signed(3) & A_signed) + (B_signed));
				WHEN "01" => R <= STD_LOGIC_VECTOR((A_signed(3) & A_signed(3) & A_signed(3) & A_signed(3) & A_signed) - (B_signed(3)
										& B_signed(3) & B_signed(3) & B_signed(3) & B_signed));
				WHEN "10" => R <= STD_LOGIC_VECTOR((A_signed) * (B_signed));
				WHEN "11" => R <= STD_LOGIC_VECTOR((A_signed(3) & A_signed(3) & A_signed(3) & A_signed(3) & A_signed) / (B_signed(3)
										& B_signed(3) & B_signed(3) & B_signed(3) & B_signed));
				WHEN OTHERS => R <= "00000000";
			END CASE;
		END PROCESS calc;
END behavior;