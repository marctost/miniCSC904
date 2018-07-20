#include "snippet.C"

int graph_section(string filename, string source_or_no, PlotterLines graphLines0, PlotterLines graphLines1, PlotterLines graphLines2, PlotterLines graphLines3, PlotterLines graphLines4);
PlotterLines resize(PlotterLines graph_line);
TGraph* make_graph(PlotterLines graph_line, int use);

void gas_gain_plot(string which_plot, string source_or_no) {
    ExcelSheet test("analysis_page_gasGain.csv");

    
    // This is the important bit! The first value (test) refers to the excel sheet above. The second number is
    // the row you start on. The second number is the lowest row you go to. Doesn't have to be exact,
    // we have a function that makes things perfect. The 3rd number is the column that you're pulling. The
    // last number is the number of adjacent columns you're using. Make sure to remember that things start
    // at zero!! So be careful.
   
    PlotterLines irr_0(test, 3, 21, 0, 3);
    PlotterLines ref_0(test, 3, 21, 0, 3);
    
    PlotterLines irr_1(test, 3, 16, 4, 3);
    PlotterLines ref_1(test, 3, 18, 7, 3);
    
    PlotterLines irr_2(test, 3, 13, 11, 3);
    PlotterLines ref_2(test, 3, 13, 14, 3);
    
    PlotterLines irr_3(test, 3, 13, 18, 3);
    PlotterLines ref_3(test, 3, 13, 21, 3);
    
    PlotterLines irr_4(test, 3, 13, 25, 3);
    PlotterLines ref_4(test, 3, 14, 28, 3);

    
    // Choose which plot you want to make.
    if (which_plot=="irr"){
        graph_section(which_plot,source_or_no, irr_0, irr_1, irr_2, irr_3, irr_4);
    }
    else if (which_plot=="ref"){
        graph_section(which_plot,source_or_no, ref_0, ref_1, ref_2, ref_3, ref_4);
    }

}

// Resizes the vectors to make sure that no extra points are being plotted than are in excel. Also fixes negative values
PlotterLines resize(PlotterLines graph_line){
    for (int g=graph_line.lines[0].size()-1; g>0; g=g-1){
        if (graph_line.lines[0].at(g)==graph_line.lines[0].at(g-1)){
            graph_line.lines[0].pop_back();
            graph_line.lines[1].pop_back();
            graph_line.lines[2].pop_back();
        }
        else{
            continue;
        }
    }
    for (int j=0; j<graph_line.lines[0].size(); j++){
        if (graph_line.lines[1].at(j)<0){
            graph_line.lines[1].at(j)=0.1;
        }
        if (graph_line.lines[2].at(j)<0){
            graph_line.lines[2].at(j)=0.1;
        }
    }
    return graph_line;
}

// Makes the graphs
TGraph* make_graph(PlotterLines graph_line, int use){
    TGraph *graph = new TGraph(graph_line.lines[0].size());
    for (int i=0; i<graph_line.lines[0].size(); i++){
        // What is plotted is the first column selected on the x axis, and then the column with the number "use" on the y axis
        graph->SetPoint(i,graph_line.lines[0].at(i), graph_line.lines[use].at(i));
    }
    return graph;
}


int graph_section(string filename, string source_or_no, PlotterLines graphLines0, PlotterLines graphLines1, PlotterLines graphLines2, PlotterLines graphLines3, PlotterLines graphLines4){
	
    TString title;
    TString ref;
    TString source;
    
    
    Color_t colors[] = {kRed-10, kRed-7, kRed, kRed+2, kRed+4};
    
    // If statements that create the title
    
    int use;
    if (source_or_no=="source"){
        use=2;
        source = ", with source";
    }
    else if (source_or_no=="no"){
        use=1;
        source = ", no source";
    }
    if (filename=="irr"){
        ref = ", irradiated layer";
    }
    else if (filename=="ref"){
        ref = ", reference layer";
    }
    title = "Gas gain"+source+ref;
    
    
    
    
    //Make sure that the vectors have the right length.
    PlotterLines line_0 = resize(graphLines0);
    PlotterLines line_1 = resize(graphLines1);
    PlotterLines line_2 = resize(graphLines2);
    PlotterLines line_3 = resize(graphLines3);
    PlotterLines line_4 = resize(graphLines4);
    
    
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

    // This function takes the line (which has been correctly re-sized), and then loops through and returns graphs.
    TGraph* graph_0 = make_graph(line_0, use);
    TGraph* graph_1 = make_graph(line_1, use);
    TGraph* graph_2 = make_graph(line_2, use);
    TGraph* graph_3 = make_graph(line_3, use);
    TGraph* graph_4 = make_graph(line_4, use);
    
    //Line colors!
    graph_0->SetLineColor(colors[0]);
    graph_1->SetLineColor(colors[1]);
    graph_2->SetLineColor(colors[2]);
    graph_3->SetLineColor(colors[3]);
    graph_4->SetLineColor(colors[4]);
    
    // Make the markers
    graph_0->SetMarkerStyle(20);
    graph_0->SetMarkerSize(0.8);
    graph_0->SetMarkerColor(colors[0]);
    graph_1->SetMarkerStyle(20);
    graph_1->SetMarkerSize(0.8);
    graph_1->SetMarkerColor(colors[1]);
    graph_2->SetMarkerStyle(20);
    graph_2->SetMarkerSize(0.8);
    graph_2->SetMarkerColor(colors[2]);
    graph_3->SetMarkerStyle(20);
    graph_3->SetMarkerSize(0.8);
    graph_3->SetMarkerColor(colors[3]);
    graph_4->SetMarkerStyle(20);
    graph_4->SetMarkerSize(0.8);
    graph_4->SetMarkerColor(colors[4]);
    
    //More formatting
    graph_0->SetLineWidth(2.0);
    graph_1->SetLineWidth(2.0);
    graph_2->SetLineWidth(2.0);
    graph_3->SetLineWidth(2.0);
    graph_4->SetLineWidth(2.0);
    
    // Label the legend by hand
    legend->AddEntry(graph_0, "Run 0, 0 mC/cm");
    legend->AddEntry(graph_1, "Run 1, 18 mC/cm");
    legend->AddEntry(graph_2, "Run 2, 26 mC/cm");
    legend->AddEntry(graph_3, "Run 3, 65 mC/cm");
    legend->AddEntry(graph_4, "Run 4, 125 mC/cm");

    // Make a multigraph to put all the stuff into and draw all at once.
    TMultiGraph *mg = new TMultiGraph();
    
    mg->Add(graph_0);
    mg->Add(graph_1);
    mg->Add(graph_2);
    mg->Add(graph_3);
    mg->Add(graph_4);
    
    // title
    mg->SetTitle(title);
    
    //Set the plot to log on the y-axis
    canvas->SetLogy();
    mg->Draw("ALP");
    canvas->SetLogy();
    
    //  label axis
    mg->GetXaxis()->SetTitle("Voltage (kV)");
    
    //mg->GetXaxis()->SetTitle("Voltage (kV)");
	//mg->GetYaxis()->SetTitle("Current (pA)");
    mg->GetXaxis()->SetRangeUser(0.2,3.8);
    

	legend->Draw("SAME");

    // Locate where it goes and gets saved, may have to be changed.
	string saveWhere = "/Users/marctost/Desktop/gas_gain_"+source_or_no+"_"+filename+".png";
	canvas->Update();
	canvas->SaveAs(saveWhere.c_str());
	canvas;

	return 0;
}
