#include "snippet.C"

int graph_section(string filename, string norm_or_no, PlotterLines hole_num, PlotterLines run_0,PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10);
TGraph* make_graph(string norm_or_no, int i, PlotterLines run_0,PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10);
float Get_average_val_ref(PlotterLines run);
TGraph* format_me(TGraph* graph, Color_t color);

void cluster_charge_plot(string which_plot, string norm_or_no) {
    ExcelSheet test("analysis_page_cluster.csv");

    // This is the important bit! The first value refers to the excel sheet above. The second number is
    // the row you start on. The second number is the lowest row you go to. Doesn't have to be exact,
    // we have a function that makes things perfect. The 3rd number is the column that you're pulling. The
    // last number is the number of adjacent columns you're using. Make sure to remember that things start
    // at zero!! So be careful.
    
    PlotterLines hole_num(test, 2, 14, 0, 1);
    PlotterLines run_0(test, 2, 14, 1, 1);
    PlotterLines run_1(test, 2, 14, 2, 1);
    PlotterLines run_2(test, 2, 14, 3, 1);
    PlotterLines run_3(test, 2, 14, 4, 1);
    PlotterLines run_4(test, 2, 14, 5, 1);
    PlotterLines run_5(test, 2, 14, 6, 1);
    PlotterLines run_6(test, 2, 14, 7, 1);
    PlotterLines run_7(test, 2, 14, 8, 1);
    PlotterLines run_8(test, 2, 14, 9, 1);
    PlotterLines run_9(test, 2, 14, 10, 1);
    PlotterLines run_10(test, 2, 14, 11, 1);
    
    graph_section(which_plot,norm_or_no, hole_num, run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
}


float Get_average_val_ref(PlotterLines run){
    float divide=2;
    float tot=0;
    for (int i=10;i<12;i++){
        if (run.lines[0].at(i)==0){
            divide=divide-1;
            continue;
        }
        tot = tot+run.lines[0].at(i);
    }
    return tot/divide;
}

// Makes the graphs
TGraph* make_graph(string norm_or_no, int i, PlotterLines run_0, PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10){
    TGraph *graph = new TGraph(6);
    
    // Note the the first number is the "point number" and will always be 0-4, the second number the accumlated charge, and the last number is charge mean

    if (norm_or_no=="ref"){
        graph->SetPoint(0, 0, run_0.lines[0].at(i)/run_0.lines[0].at(11));
        graph->SetPoint(1, 53, run_1.lines[0].at(i)/run_1.lines[0].at(11));
        graph->SetPoint(2, 95, run_2.lines[0].at(i)/run_2.lines[0].at(11));
        graph->SetPoint(3, 121, run_3.lines[0].at(i)/run_3.lines[0].at(11));
        graph->SetPoint(4, 149, run_4.lines[0].at(i)/run_4.lines[0].at(11));
        graph->SetPoint(5, 180, run_5.lines[0].at(i)/run_5.lines[0].at(11));
        //graph->SetPoint(6, 200, run_6.lines[0].at(i)/run_6.lines[0].at(11));
        //graph->SetPoint(7, 205, run_7.lines[0].at(i)/run_7.lines[0].at(11));
        //graph->SetPoint(8, 210, run_8.lines[0].at(i)/run_8.lines[0].at(11));
        //graph->SetPoint(9, 215, run_9.lines[0].at(i)/run_9.lines[0].at(11));
        //graph->SetPoint(10, 220, run_10.lines[0].at(i)/run_10.lines[0].at(11));
    }
    else if (norm_or_no=="irr"){
        graph->SetPoint(0, 0, run_0.lines[0].at(i)/run_0.lines[0].at(5));
        graph->SetPoint(1, 53, run_1.lines[0].at(i)/run_1.lines[0].at(5));
        graph->SetPoint(2, 95, run_2.lines[0].at(i)/run_2.lines[0].at(5));
        graph->SetPoint(3, 121, run_3.lines[0].at(i)/run_3.lines[0].at(5));
        graph->SetPoint(4, 149, run_4.lines[0].at(i)/run_4.lines[0].at(5));
        graph->SetPoint(5, 180, run_5.lines[0].at(i)/run_5.lines[0].at(5));
        //graph->SetPoint(6, 200, run_6.lines[0].at(i)/run_6.lines[0].at(5));
        //graph->SetPoint(7, 205, run_7.lines[0].at(i)/run_7.lines[0].at(5));
        //graph->SetPoint(8, 210, run_8.lines[0].at(i)/run_8.lines[0].at(5));
        //graph->SetPoint(9, 215, run_9.lines[0].at(i)/run_9.lines[0].at(5));
        //graph->SetPoint(10, 220, run_10.lines[0].at(i)/run_10.lines[0].at(5));
    }
    else{
        graph->SetPoint(0, 0, run_0.lines[0].at(i));
        graph->SetPoint(1, 53, run_1.lines[0].at(i));
        graph->SetPoint(2, 95, run_2.lines[0].at(i));
        graph->SetPoint(3, 121, run_3.lines[0].at(i));
        graph->SetPoint(4, 149, run_4.lines[0].at(i));
        graph->SetPoint(5, 180, run_5.lines[0].at(i));
        //graph->SetPoint(6, 200, run_6.lines[0].at(i));
        //graph->SetPoint(7, 205, run_7.lines[0].at(i));
        //graph->SetPoint(8, 210, run_8.lines[0].at(i));
        //graph->SetPoint(9, 215, run_9.lines[0].at(i));
        //graph->SetPoint(10, 220, run_10.lines[0].at(i));
    }
    return graph;
}

TGraph* format_me(TGraph* graph, Color_t color){
    graph->SetLineColor(color);
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(0.8);
    graph->SetMarkerColor(color);
    graph->SetLineWidth(2.0);
    
    return graph;
}



int graph_section(string filename, string norm_or_no, PlotterLines hole_num, PlotterLines run_0,PlotterLines run_1, PlotterLines run_2, PlotterLines run_3, PlotterLines run_4, PlotterLines run_5, PlotterLines run_6, PlotterLines run_7, PlotterLines run_8, PlotterLines run_9, PlotterLines run_10){
	
    TString title;
    TString label;
    label = " ";
    if (norm_or_no=="ref"){
        label = ", normalized to reference (3,1)";
    }
    else if (norm_or_no=="irr"){
        label = ", normalized to irradiated (3,1)";
    }
    title = "Cluster charge MPV"+label;
    
    
    
    // For this plot, the "i" in graphLine.line[thing].at(i) refers to which hole is being sourced. Guidlines here:
    // None: i=0
    // Irr 1,1: i=1
    // Irr 1,2: i=2
    // Irr 2,1: i=3
    // Irr 2,2: i=4
    // Irr 3,1: i=5
    // Irr 3,2: i=6
    // Ref 1,1: i=7
    // Ref 1,2: i=8
    // Red 2,1: i=9
    // Ref 2,2: i=10
    // Ref 3,1: i=11
    // Ref 3,2: i=12
    
    
    Color_t colors[] = {kBlue-10, kBlue-7, kBlue, kBlue+2, kAzure+4, kAzure+1, kRed, kRed+3, kRed-6, kOrange-3, kRed-3, kOrange+4};
    
	//Just some styling stuff
	gROOT->SetBatch(true);
	gStyle->SetOptStat(2210);
	gStyle->SetTitleAlign(23);

	//References for changing margins and the size of the canvas
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

    // This function takes the line (which has been correctly sized), and then loops through and returns graphs.
    TGraph* graph_irr_2_1 = make_graph(norm_or_no,3,run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
    TGraph* graph_irr_2_2 = make_graph(norm_or_no,4,run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
    TGraph* graph_irr_3_1 = make_graph(norm_or_no,5,run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
    TGraph* graph_irr_3_2 = make_graph(norm_or_no,6,run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
    TGraph* graph_ref_2_2 = make_graph(norm_or_no,10,run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
    TGraph* graph_ref_3_1 = make_graph(norm_or_no,11,run_0, run_1, run_2, run_3, run_4, run_5, run_6, run_7, run_8, run_9, run_10);
    
    TGraph* fin_graph_irr_2_1 = format_me(graph_irr_2_1, colors[6]);
    TGraph* fin_graph_irr_2_2 = format_me(graph_irr_2_2, colors[7]);
    TGraph* fin_graph_irr_3_1 = format_me(graph_irr_3_1, colors[8]);
    TGraph* fin_graph_irr_3_2 = format_me(graph_irr_3_2, colors[9]);
    TGraph* fin_graph_ref_2_2 = format_me(graph_ref_2_2, colors[0]);
    TGraph* fin_graph_ref_3_1 = format_me(graph_ref_3_1, colors[1]);
    
    
    // Still the legend, label by hand
    legend->AddEntry(fin_graph_irr_2_1, "Irr (2,1)");
    legend->AddEntry(fin_graph_irr_2_2, "Irr (2,2) (irr)");
    legend->AddEntry(fin_graph_irr_3_1, "Irr (3,1)");
    legend->AddEntry(fin_graph_irr_3_2, "Irr (3,2)");
    
    if (norm_or_no!="irr"){
        legend->AddEntry(fin_graph_ref_3_1, "Ref (3,1)");
        legend->AddEntry(fin_graph_ref_2_2, "Ref (2,2)");
    }
        
        
    // Make a multigraph to put all the stuff into and draw all at once.
    TMultiGraph *mg = new TMultiGraph();
    
    if (norm_or_no!="irr"){
        mg->Add(fin_graph_ref_3_1);
        mg->Add(fin_graph_ref_2_2);
    }
    mg->Add(fin_graph_irr_2_1);
    mg->Add(fin_graph_irr_2_2);
    mg->Add(fin_graph_irr_3_1);
    mg->Add(fin_graph_irr_3_2);
    
    // title!
    mg->SetTitle(title);
    
    mg->Draw("ALP");

    
    //  label
    mg->GetXaxis()->SetTitle("Accumulated charge (mC/cm)");
    mg->GetYaxis()->SetTitle("ADC counts");
    if (norm_or_no=="ref" or norm_or_no=="irr"){
        mg->GetYaxis()->SetRangeUser(0.86, 1.3);
    }
    else{
        mg->GetYaxis()->SetRangeUser(900, 1600);
    }

	legend->Draw("SAME");

    // Save plots
    system("mkdir -p Plots");
	string saveWhere = "Plots/cluster_"+filename+norm_or_no+".png";
	canvas->Update();
	canvas->SaveAs(saveWhere.c_str());
	canvas;

	return 0;
}
