        private void Calculate_Click(object sender, EventArgs e)
        {
            if (!double.TryParse(txtHeight.Text, out double wysokosc) || !double.TryParse(txtLength.Text, out double dlugosc))
            {

            }

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SchodyApp
{
    public partial class Kalkulator : Program
    {
        public Kalkulator()
        {
            InitializeComponent();
        }

        private int ObliczIloscStopni(double wysokosc, double dlugosc)
        {
            const double minWysokosc = 15.0;
            const double maxWysokosc = 17.0;
            const double minDlugosc = 28.0;
            const double maxDlugosc = 30.0;

            int iloscStopniWysokosc = (int)Math.Floor(wysokosc / minWysokosc);
            int iloscStopniDlugosc = (int)Math.Floor(dlugosc / minDlugosc);

            if (iloscStopniWysokosc <= 0 || iloscStopniDlugosc <= 0)
            {
                return -1;
            }

            int iloscStopni = Math.Min(iloscStopniWysokosc, iloscStopniDlugosc);

            double dlugoscStopnia = dlugosc / iloscStopni;
            if (dlugoscStopnia > maxDlugosc)
            {
                return -1;
            }

            return iloscStopni;
        }

        private void ObliczWymiaryStopnia(double dlugosc, double wysokosc, int iloscStopni, out double dlugoscStopnia, out double wysokoscStopnia)
        {
            dlugoscStopnia = dlugosc / iloscStopni;
            wysokoscStopnia = wysokosc / iloscStopni;
        }
    }
}
