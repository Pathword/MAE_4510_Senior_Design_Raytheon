from wand.image import Image

f = "C:\\Users\\dcopley\\Documents\\Compiler\\ANTH\\Colin Wren\\APR Colin Wren 2016.pdf"

with(Image(filename=f, resolution=120)) as source:
    for i, image in enumerate(source.sequence):
        newfilename = f[:-4] + str(i + 1) + '.jpeg'
        Image(image).save(filename=newfilename)