LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;           -- need for to_unsigned

ENTITY phonenumdisplayertb IS     --this is the test bench entity.
END ENTITY phonenumdisplayertb;   --It has a different name than the module you are testing

ARCHITECTURE test OF phonenumdisplayertb IS

    -- Component Declaration for the Unit Under Test (UUT)
    COMPONENT phonenumdisplayer      --the component name must match your lab4 entity name
        PORT (
            x           : IN  std_logic;  --these port names must match your
            y           : IN  std_logic;  --entity port names exactly
            z           : IN  std_logic;
            w           : IN  std_logic;
            ----------------------------  
            c    : OUT std_logic_vector(6 downto 0); 
            i      : OUT std_logic_vector(6 downto 0)            
            ); 
    END COMPONENT;


    --Inputs
    SIGNAL inputs : std_logic_vector(3 DOWNTO 0);       --this vector will drive the inputs

    --Outputs
    SIGNAL c_tb : std_logic_vector(6 downto 0); 
    SIGNAL i_tb   : std_logic_vector(6 downto 0);--these names can be anything
    
BEGIN
    -- Instantiate the Unit Under Test (UUT)
	 -- on left of => are the names of your component's ports above
	 -- on the right of => are the signals that they map to
    uut : phonenumdisplayer PORT MAP(
        x           => inputs(3),
        y           => inputs(2),
        z           => inputs(1),
        w           => inputs(0),
        
        --
  
        c   => c_tb,
        i     => i_tb
        );


    ---------------------------------------------------------------------------
    -- NAME: Stimulus
    --
    -- DESCRIPTION:
    --    This process will apply the  stimulus to the UUT
    ---------------------------------------------------------------------------
    stimulus : PROCESS
    BEGIN
        FOR i IN 0 TO 15 LOOP
            inputs <= std_logic_vector(to_unsigned(i,4));
            WAIT FOR 10 ns;
        END LOOP;

        -----------------------------------------------------------------------
        -- This last WAIT statement needs to be here to prevent the PROCESS
        -- sequence from restarting.
        -----------------------------------------------------------------------
        WAIT;
        
    END PROCESS stimulus;

END ARCHITECTURE test;
