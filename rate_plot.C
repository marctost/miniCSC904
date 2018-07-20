#include "snippet.C"

int graph_section(string filename, PlotterLines graphLines, PlotterLines subtraction, string subtract_or_no, string irr_or_ref, string type);

void rate_plot(string which_plot, string subtract_or_no, string irr_or_ref, string type) {
    ExcelSheet test("final_numbers_rate.csv");
    
TString get_leg(int j, TString charge);

    // This is the inportant bit! The first value (test) refers to the excel sheet above. The second number is
    // the row your numbers start on. The second number is the lowest row you go to. The 3rd number is the first column that you're pulling data from. The
    // last number is the number of adjacent columns you're using. Make sure to remember that things start
    // at zero!! So be careful.
    
    PlotterLines ALCT_dark(test, 2, 27, 2, 5);
    PlotterLines CLCT_dark(test, 2, 27, 8, 5);
    PlotterLines LCT_dark(test, 2, 27, 14, 5);
    
    PlotterLines ALCT_top_irr(test, 94, 119, 2, 5);
    PlotterLines CLCT_top_irr(test, 94, 119, 8, 5);
    PlotterLines LCT_top_irr(test, 94, 119, 14, 5);

    PlotterLines ALCT_top(test, 33, 58, 2, 5);
    PlotterLines CLCT_top(test, 33, 58, 8, 5);
    PlotterLines LCT_top(test, 33, 58, 14, 5);

    PlotterLines ALCT_bottom(test, 64, 89, 2, 5);
    PlotterLines CLCT_bottom(test, 64, 89, 8, 5);
    PlotterLines LCT_bottom(test, 64, 89, 14, 5);
    
    
    // Choose which plot you do. All the different options have their own call in the bash script.
    
    if (which_plot=="ALCT_dark"){
        graph_section(which_plot,ALCT_dark, ALCT_dark, subtract_or_no, irr_or_ref, type);
    }
    else if (which_plot=="ALCT_top"){
        graph_section(which_plot,ALCT_top, ALCT_dark, subtract_or_no, irr_or_ref, type);
    }
    else if (which_plot=="ALCT_bottom"){
        graph_section(which_plot,ALCT_bottom, ALCT_dark, subtract_or_no, irr_or_ref, type);
    }
    else if (which_plot=="ALCT_top_irr"){
        graph_section(which_plot,ALCT_top_irr, ALCT_dark, subtract_or_no, irr_or_ref, type);
    }
    else if (which_plot=="CLCT_dark"){
        graph_section(which_plot,CLCT_dark, CLCT_dark, subtract_or_no, irr_or_ref, type);
    }
    else if (which_plot=="CLCT_top"){
        graph_section(which_plot,CLCT_top, CLCT_dark, subtract_or_no, irr_or_ref, type);
    }
    else if (which_plot=="CLCT_bottom"){
        graph_section(which_plot,CLCT_bottom, CLCT_dark, subtract_or_no, irr_or_ref, type);
    }
    else if (which_plot=="CLCT_top_irr"){
        graph_section(which_plot,CLCT_top_irr, CLCT_dark, subtract_or_no, irr_or_ref, type);
    }
    else if (which_plot=="LCT_dark"){
        graph_section(which_plot,LCT_dark, LCT_dark, subtract_or_no, irr_or_ref, type);
    }
    else if (which_plot=="LCT_top"){
        graph_section(which_plot,LCT_top, LCT_dark, subtract_or_no, irr_or_ref, type);
    }
    else if (which_plot=="LCT_bottom"){
        graph_section(which_plot,LCT_bottom, LCT_dark, subtract_or_no, irr_or_ref, type);
    }
    else if (which_plot=="LCT_top_irr"){
        graph_section(which_plot,LCT_top_irr, LCT_dark, subtract_or_no, irr_or_ref, type);
    }
    
}

TString get_leg(int j, TString charge){
    TString name;
    
    //Simple function that takes the info given and creates a label for the legend.
    
    if (j==0){
        name = "Run 0"+charge;
    }
    else if (j==1){
        name = "Run 1"+charge;
    }
    else if (j==2){
        name = "Run 2"+charge;
    }
    else if (j==3){
        name = "Run 3"+charge;
    }
    else if (j==4){
        name = "Run 4"+charge;
    }
    else if (j==5){
        name = "Run 5"+charge;
    }
    else if (j==6){
        name = "Run 6"+charge;
    }
    
    return name;
}




int graph_section(string filename, PlotterLines graphLines, PlotterLines subtraction, string subtract_or_no, string irr_or_ref, string type){
	
    int move_color=0;
    TString title;
    TString sub;
    TString type_name;
    TString layer;
    
    
    // All these if functions take the argument provided when calling the program initially and create a nice title for the plot.
    if (subtract_or_no=="subtract"){
        sub = ", Background subtracted";
    }
    else if (subtract_or_no=="no"){
        sub = " ";
    }
    if (irr_or_ref=="irr"){
        layer = " Irradiated layer (3,1),";
    }
    if (irr_or_ref=="irr_irr"){
        layer = " Irradiated layer (2,2) (irr),";
        move_color=6;
    }
    else if (irr_or_ref=="ref"){
        layer = " Reference layer (2,2),";
    }
    else if (irr_or_ref=="dark"){
        layer = " Dark,";
        sub = " ";
    }
    if (type=="LCT"){
        type_name=" LCT rate";
    }
    else if (type=="CLCT"){
        type_name=" CLCT rate";
    }
    else if (type=="ALCT"){
        type_name=" ALCT rate";
    }
    
    title =layer+type_name+sub;

    
    // These are the colors that will go into the plot. When the irradiated hole gets called, it is bumped +6.
    Color_t colors[] = {kBlue-10, kBlue-7, kBlue, kBlue+2, kAzure+4, kAzure+1, kRed-10, kRed-7, kRed, kRed+2, kRed+4};
    // The accumulated charge of each run, used to make the legend
    TString acc_charges[] = {", 0 mC/cm", ", 53 mC/cm", ", 95 mC/cm", ", 121 mC/cm", ", 149 mC/cm"};
    
    
	int number_of_points=graphLines.size;
    //Number of lines that are going to be put on the plot (= # of runs)
    int number_of_lines=5;


    // if sub_or_no = sub, then don't add the background back it (it has been subtracted in the excel document). If it = no, then add the background back in to return it to the raw, un-subtracted data

    if (subtract_or_no=="subtract"){
        for (int q=0; q<number_of_lines; q++){
            for (int w=0; w<number_of_points; w++){
                subtraction.lines[q].at(w)=0;
            }
        }
    }
    
    
    
	//Just some styling stuff
	gROOT->SetBatch(true);
	gStyle->SetOptStat(2210);
	gStyle->SetTitleAlign(23);

	//References for changing margins, the size of the canvas, and the size of the legend
	int H = 800;
	int W = H;
	float T = 0.08*H;
	float B = 0.12*H;
	float L = 0.12*W;
	float R = 0.04*W;
	float x1_l = 0.48;
	float y1_l = 0.90;
	float dx_l = 0.30;
	float dy_l = 0.30;
	float x0_l = x1_l-dx_l;
	float y0_l = y1_l-dy_l;



	//make the canvas, set its properties
	TCanvas *canvas = new TCanvas("c2","c2",50,50,W,H);
	canvas->SetFillColor(0);
	canvas->SetBorderMode(0);
	canvas->SetFrameFillStyle(0);
	canvas->SetFrameBorderMode(0);
	canvas->SetLeftMargin( L/W );
	canvas->SetRightMargin( R/W );
	canvas->SetTopMargin( T/H );
	canvas->SetBottomMargin( B/H );
	canvas->cd();


    
	//the legend happens
	TLegend *legend = new TLegend(x0_l,y0_l,x1_l,y1_l,"","brNDC");
	legend->SetBorderSize(1);


	//loop over the various files, and the points in it
	for (int j=0; j<number_of_lines; j++){
        //Create the graph by looping over the number of points
		TGraph *graph = new TGraph(number_of_points);
		for (int i=0; i<number_of_points; i++){
            if (graphLines.lines[j].at(i)<0){
                // Note that we are using the .voltages here, this is specific to the rate plots, and it automatically picks the "0" column, where the voltages are located.
                graph->SetPoint(i, graphLines.voltages.at(i),0);
            }
            else{
                graph->SetPoint(i,graphLines.voltages.at(i),graphLines.lines[j].at(i)+ subtraction.lines[j].at(i));
			}
        }

        // Some maintanence and labeling for the plot.
		graph->GetXaxis()->SetTitle("Voltage (kV)");
		graph->GetYaxis()->SetTitle("Hertz");
		graph->SetLineColor(colors[j+move_color]);
		graph->SetLineWidth(2.0);
        
        // Use the function to great the legend entries one by one
        TString lengend_title = get_leg(j, acc_charges[j]);
		legend->AddEntry(graph, lengend_title);
		
        //Manually set the dimensions of the plot to keep it consistent for all rate plots
        graph->SetMaximum(600);
        graph->GetXaxis()->SetRangeUser(2,4);
        
        //Some line styling.
        graph->SetMarkerStyle(20);
        graph->SetMarkerSize(0.8);
        graph->SetMarkerColor(colors[j+move_color]);
        
        // Draw the plots
        if (j==0){
            graph->SetTitle(title);
			graph->Draw();
		}
		else{
        
			graph->Draw("SAME P L");
		}


	}

	legend->Draw("SAME");
    
    // Add a line at 3.6 kV
    canvas->Update();
    TLine *line = new TLine(3.6, 0, 3.6, 600);
    line->SetLineColor(kPink-9);
    line->SetLineWidth(2.0);
    line->Draw();
    
    

    // Save the plot to the desktop.
	string saveWhere = "/Users/marctost/Desktop/"+filename+"_"+subtract_or_no+".png";
	canvas->Update();
	canvas->SaveAs(saveWhere.c_str());
    //canvas->Print(filename+".png");
	canvas;


	return 0;
}
