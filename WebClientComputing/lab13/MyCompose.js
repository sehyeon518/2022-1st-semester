export default function MyCompose(...HOCs) {
        return HOCs.reduce((f0, f1) => (x0) => f0(f1(x0)));
}
