#include "snippet.C"

int graph_section(PlotterLines voltage, PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10);
TGraph* make_graph(PlotterLines voltage, PlotterLines graph_line);

void gas_gain_plot() {
    ExcelSheet test("analysis_page_gasGain.csv");

    
    // This is the important bit! The first value (test) refers to the excel sheet above. The second number is
    // the row you start on. The second number is the lowest row you go to. Doesn't have to be exact,
    // we have a function that makes things perfect. The 3rd number is the column that you're pulling. The
    // last number is the number of adjacent columns you're using. Make sure to remember that things start
    // at zero!! So be careful.
   
    PlotterLines voltage(test, 1, 12, 0, 1);
    PlotterLines run_0(test, 1, 12, 1, 1);
    PlotterLines run_1(test, 1, 12, 2, 1);
    PlotterLines run_2(test, 1, 12, 3, 1);
    PlotterLines run_3(test, 1, 12, 4, 1);
    PlotterLines run_4(test, 1, 12, 5, 1);
    PlotterLines run_5(test, 1, 12, 6, 1);
    PlotterLines run_6(test, 1, 12, 7, 1);
    PlotterLines run_7(test, 1, 12, 8, 1);
    PlotterLines run_8(test, 1, 12, 9, 1);
    PlotterLines run_9(test, 1, 12, 10, 1);
    PlotterLines run_10(test, 1, 12, 11, 1);

    graph_section(voltage,run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
}


//Formats the graphs in the appropriate way
TGraph* format_graph(TGraph* graph, Color_t color, float alpha){
    graph->SetLineColorAlpha(color, alpha);
    graph->SetMarkerSize(0.8);
    graph->SetMarkerStyle(20);
    graph->SetMarkerColorAlpha(color, alpha);
    graph->SetLineWidth(2.0);
    return graph;
}


// Makes the graphs
TGraph* make_graph(PlotterLines voltage, PlotterLines graph_line, Color_t color, float alpha){
    TGraph *graph = new TGraph(graph_line.lines[0].size());
    for (int i=0; i<graph_line.lines[0].size(); i++){
        graph->SetPoint(i,voltage.lines[0].at(i), graph_line.lines[0].at(i));
    }
    TGraph* graph_fin = format_graph(graph, color, alpha);
    return graph_fin;
}


int graph_section(PlotterLines voltage, PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10){
    
    TString title = "Absolute gas gain";
    
	//Just some styling stuff
	gROOT->SetBatch(true);
	gStyle->SetOptStat(2210);
	gStyle->SetTitleAlign(23);

	//References for margin, canvas and legend
	int H = 800;
	int W = H;
	float T = 0.08*H;
	float B = 0.12*H;
	float L = 0.12*W;
	float R = 0.04*W;
	float x1_l = 0.38;
	float y1_l = 0.90;
	float dx_l = 0.20;
	float dy_l = 0.20;
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

    // This is where the graphs are made. Given argument voltage, which run to do, the color and the transparency of the color. Formatting is done here too.
    TGraph* graph_0 = make_graph(voltage, run_0, kRed, 0.1);
    TGraph* graph_1 = make_graph(voltage, run_1, kRed, 0.2);
    TGraph* graph_2 = make_graph(voltage, run_2, kRed, 0.3);
    TGraph* graph_3 = make_graph(voltage, run_3, kRed, 0.4);
    TGraph* graph_4 = make_graph(voltage, run_4, kRed+2, 1);
    // TGraph* graph_5 = make_graph(voltage, run_5, kRed+2, 1);
    // TGraph* graph_6 = make_graph(voltage, run_6, kRed, 0.7);
    // TGraph* graph_7 = make_graph(voltage, run_7, kRed, 0.1);
    // TGraph* graph_8 = make_graph(voltage, run_8, kRed, 0.1);
    // TGraph* graph_9 = make_graph(voltage, run_9, kRed, 0.1);
    // TGraph* graph_10 = make_graph(voltage, run_10, kRed, 0.1);

    

    
    // Label the legend by hand
    legend->AddEntry(graph_0, "Run 0, 0 mC/cm");
    legend->AddEntry(graph_1, "Run 1, 18 mC/cm");
    legend->AddEntry(graph_2, "Run 2, 26 mC/cm");
    legend->AddEntry(graph_3, "Run 3, 65 mC/cm");
    legend->AddEntry(graph_4, "Run 4, 125 mC/cm");
    //legend->AddEntry(graph_5, "Run 5, 180 mC/cm");
    //legend->AddEntry(graph_6, "Run 6, ? mC/cm");
    //legend->AddEntry(graph_7, "Run 7, ? mC/cm");
    //legend->AddEntry(graph_8, "Run 8, ? mC/cm");
    //legend->AddEntry(graph_9, "Run 9, ? mC/cm");
    //legend->AddEntry(graph_10, "Run 10, ? mC/cm");
    
    
    // Make a multigraph to put all the stuff into and draw all at once.
    TMultiGraph *mg = new TMultiGraph();
    
    mg->Add(graph_0);
    mg->Add(graph_1);
    mg->Add(graph_2);
    mg->Add(graph_3);
    mg->Add(graph_4);
    //mg->Add(graph_5);
    //mg->Add(graph_6);
    //mg->Add(graph_7);
    //mg->Add(graph_8);
    //mg->Add(graph_9);
    //mg->Add(graph_10);
    
    
    // title
    mg->SetTitle(title);
    
    //Set the plot to log on the y-axis
    canvas->SetLogy();
    mg->Draw("ALP");
    canvas->SetLogy();
    
    //  label axis
    mg->GetXaxis()->SetTitle("Voltage (kV)");
    mg->GetXaxis()->SetRangeUser(0.2,3.8);
    

	legend->Draw("SAME");

    // Save plot
    system("mkdir -p Plots");
	string saveWhere = "Plots/gas_gain.pdf";
	canvas->Update();
	canvas->SaveAs(saveWhere.c_str());
	canvas;

	return 0;
}
