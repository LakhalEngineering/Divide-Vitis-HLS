
void divide(unsigned char N, unsigned char D, unsigned *Q, unsigned *R)
{

    // Check if D is not zero
    if (D != 0)
    {
        *Q = 0;
        *R = 0;

        // Count from 7 downto 0
        for (int i = 7; i >= 0; i--){
            // Shift left R by one
            *R = *R << 1;

            // Get the i bit of N
            // Get the value N(i)
            char ibitN = (N & (1 << i )) >> i;

            // Set the LSB of R to the vale in iBiTN
            // R(0) := N(i)
            *R ^= (-ibitN ^ (*R)) & (1 << 0);

            if ((*R) >= D)
            {
                // Subtract R
                *R = *R - D;

                // Set the i bit of Q
                *Q |= 1 << i;
            }
        }
    }
}
