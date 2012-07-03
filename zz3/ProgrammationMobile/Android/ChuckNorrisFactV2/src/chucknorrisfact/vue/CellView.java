package chucknorrisfact.vue;

import android.widget.TextView;

/**
 * Repr�sente la vue d'une cellule de la liste
 * @author Maxime ESCOURBIAC Jean-Christophe SEPTIER
 *
 */
public class CellView {
	
	private TextView mFactTitre;	// Texte du num�ro d'Id
	
	/**
	 * Getter du TextView factTitre
	 * @return Le textView
	 */
	public TextView getFactTitre() {
		return mFactTitre;
	}

	/**
	 * Setter du TextView factTitre
	 * @param factTitre TextView factTitre
	 */
	public void setFactTitre(TextView factTitre) {
		this.mFactTitre = factTitre;
	}

	/**
	 * Change le texte de notre TextView
	 * @param titre Texte � mettre dans notre TextView
	 */
	public void setFactTitreText(String titre)
	{
		this.mFactTitre.setText(titre);
	}
}
